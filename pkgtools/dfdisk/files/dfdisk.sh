#!@SH@
#
# $NetBSD: dfdisk.sh,v 1.1.1.1 2003/04/17 11:12:52 jmmv Exp $
#
# dfdisk - Fetch distfiles from multiple locations
# Copyright (c) 2003, Julio Merino <jmmv@netbsd.org>
#
# Redistribution and use in source and binary forms, with or without
# modification, are permitted provided that the following conditions
# are met:
# 1. Redistributions of source code must retain the above copyright
#    notice, this list of conditions and the following disclaimer.
# 2. Redistributions in binary form must reproduce the above copyright
#    notice, this list of conditions and the following disclaimer in
#    the documentation and/or other materials provided with the
#    distribution.
# 3. Neither the name of author nor the names of its contributors may
#    be used to endorse or promote products derived from this software
#    without specific prior written permission.
#
# THIS SOFTWARE IS PROVIDED BY THE NETBSD FOUNDATION, INC. AND CONTRIBUTORS
# ``AS IS'' AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED
# TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
# PURPOSE ARE DISCLAIMED.  IN NO EVENT SHALL THE FOUNDATION OR CONTRIBUTORS
# BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
# CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
# SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
# INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
# CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
# ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
# POSSIBILITY OF SUCH DAMAGE.
#

ProgName="`basename $0`"
ProgVersion="@PKGVERSION@"
ConfFile="@PKG_SYSCONFDIR@/dfdisk.conf"
# dfdisk_* variables are also considered global

# ------------------------------------------------------------------------
# Miscellaneous functions
# ------------------------------------------------------------------------

err() {
    local _code

    $CD_UMOUNT 2>/dev/null || true
    _code=$1; shift
    echo "$ProgName: $*"
    exit $_code
}

warn() {
    echo "WARNING: $*"
}

quotemeta() {
    local qm_var qm_value

    qm_var="$1"
    eval qm_value=\"\$$qm_var\"

    qm_char='-e s|\/|\\\/|g'
    qm_char="$qm_char -e s/\./\\\./g"
    qm_char="$qm_char -e s/\?/\\\?/g"
    qm_char="$qm_char -e s/\+/\\\+/g"
    qm_char="$qm_char -e s/\*/\\\*/g"
    qm_char="$qm_char -e s/\\\"/\\\\\"/g"

    qm_value="`echo $qm_value | sed $qm_char`"
    eval $qm_var=\"\$qm_value\"
}

# ------------------------------------------------------------------------
# CD routines
# ------------------------------------------------------------------------

cd_mount() {
    $CD_MOUNT
    if [ $? -ne 0 ]; then
        err 1 "mount failed: $CD_MOUNT"
    fi
}

cd_umount() {
    $CD_UMOUNT
    if [ $? -ne 0 ]; then
        err 1 "umount failed: $CD_UMOUNT"
    fi
}

cd_current_is() {
    local _mounted _ret _cd _cds

    _mounted=yes
    if [ -z "`mount | grep $CD_DIR`" ]; then
        _mounted=no
        $CD_MOUNT 2>/dev/null
        if [ $? -ne 0 ]; then
            return 1
        fi
    fi

    _ret=1
    _cds="`cd $DBDIR; ls`"
    for _cd in $_cds; do
        _stamp="`md5 $CD_DIR | cut -d ' ' -f 4`"
        if [ -n "`grep $_stamp $DBDIR/$_cd/info`" ]; then
            _ret=0
            break
        fi
    done

    if [ "$_mounted" = "no" ]; then
        $CD_UMOUNT 2>/dev/null
    fi

    return $_ret
}

# ------------------------------------------------------------------------
# Add target
# ------------------------------------------------------------------------

do_add() {
    local _info _stamp _dir

    if [ ! -d "$DBDIR" ]; then
        mkdir -p "$DBDIR" >/dev/null 2>&1
        if [ $? -ne 0 ]; then
            err 1 "cannot create \`$DBDIR'; permission denied?"
        fi
    elif [ ! -w "$DBDIR" ]; then
        err 1 "cannot write to \`$DBDIR'; permission denied?"
    fi

    cd_mount
    _stamp="`md5 $CD_DIR | cut -d ' ' -f 4`"
    echo "Media ID: $_stamp"

    _dir="$DBDIR/$_stamp"
    if [ -d "$_dir" ]; then
        cd_umount
        err 1 "this CD is already registered"
    fi

    echo "Scanning CD (searching a dfdisk.info file)..."
    _info="`find $CD_DIR -name dfdisk.info -print`"

    # Fill in the CD info file
    if [ -n "$_info" ]; then
        echo "Found, using $_info:"
        . "$_info"
        echo "- Disk name: $dfdisk_name"
        echo "- Path to distfiles: $dfdisk_subdir"
        mkdir -p $_dir
        cp -f "$_info" $_dir/info
        chmod 644 $_dir/info
    else
        echo "No dfdisk.info file found; enter data manually."
        ask_info
        if [ ! -d "$CD_DIR/$dfdisk_subdir" ]; then
            err 1 "the specified directory cannot be found"
        fi
        mkdir -p $_dir
        write_info $_dir/info
    fi

    # Store stamp in local control file
    echo >> $_dir/info
    echo "# Appended by @PKGBASE@ @PKGVERSION@" >> $_dir/info
    echo "# `date`" >> $_dir/info
    echo "dfdisk_stamp=$_stamp" >> $_dir/info

    # Generate file list
    echo "Generating file list..."
    ( cd $CD_DIR && find $dfdisk_subdir -type f -print > $_dir/contents )
    chmod 644 $_dir/contents
    cd_umount
}

# ------------------------------------------------------------------------
# Clean target
# ------------------------------------------------------------------------

do_clean() {
    local _cds _cd _files _file _f _found

    if [ -d $DBDIR ]; then
        _cds="`cd $DBDIR; ls`"
        if [ -z "$_cds" ]; then
            echo "No known disks; nothing to be done."
        else
            echo "Removing files..."
            _files="`find $DISTDIR -type f -print`"
            for _file in $_files; do
                _f="`echo $_file | sed -e s,$DISTDIR,,`"
                quotemeta _f
                _found=""
                for _cd in $_cds; do
                    if [ -n "`egrep $_f\$ $DBDIR/$_cd/contents`" ]; then
                        _found=yes
                        break
                    fi
                done
                if [ -n "$_found" ]; then
                    rm -f $_file
                fi
            done
            echo "Removing empty directories..."
            rmdir -p `find $DISTDIR -type d -print` 2>/dev/null || true
        fi
    else
        echo "No known disks; nothing to be done."
    fi
}

# ------------------------------------------------------------------------
# Fetch target
# ------------------------------------------------------------------------

do_fetch() {
    local _cds _cd _qdn _url _subdir _distname _found _res _key

    _url="$1"

    if [ -z "`pwd | grep $DISTDIR`" ]; then
        warn "you are not inside the distdir tree!"
        echo
        _subdir=""
    else
        _subdir="`pwd | sed -e s,$DISTDIR,,`/"
    fi

    set -- `echo $_url | tr '/' ' '`
    while [ $# -gt 1 ]; do shift; done
    _distname="$1"

    if [ ! -d $DBDIR ]; then
        echo "No disks registered in the database."
        fetch_ftp $_url
        return
    fi

    _cds="`cd $DBDIR; ls`"
    _found=""
    _qdn="$_distname"
    quotemeta _qdn
    for _cd in $_cds; do
        _res=`egrep "$_subdir$_qdn\$" $DBDIR/$_cd/contents`
        if [ -n "$_res" ]; then
            . $DBDIR/$_cd/info
            _found="$_cd"; break
        fi
    done

    if [ -z "$_found" ]; then
        echo "$_distname not found in the database."
        fetch_ftp $_url
    else
        . "$DBDIR/$_found/info"
        echo "$_distname found in the database."

        while ! cd_current_is $dfdisk_stamp; do
            echo "Wrong disk in drive (or no disk).  You can:"
            echo "- Insert the CD given below and press [RETURN]"
            echo "    $dfdisk_name"
            echo "- Type \`1' and press [RETURN] to refetch the file from the network"
            echo "    $_url"
            printf "Your choice> "
            read _key
            if [ "$_key" = "1" ]; then
                fetch_ftp $_url
                return
            fi
            # The default action (fetch from CD) is handled outside the
            # while loop.
        done

        echo "Copying `basename $1` to `pwd`"
        cd_mount
        cp "$CD_DIR/$dfdisk_subdir/$_subdir/$_distname" .
        cd_umount
    fi
}

fetch_ftp() {
    echo "Using \`$FTPCMD' to fetch $1"
    $FTPCMD $1
}

# -------------------------------------------------------------------------
# Mkinfo target
# -------------------------------------------------------------------------

do_mkinfo() {
    local _file

    _file="$1"

    ask_info

    if [ -z "$_file" ]; then
        printf "Enter file name [$DISTDIR/dfdisk.info]: "
        read _file
        if [ -z "$_file" ]; then
            _file="$DISTDIR/dfdisk.info"
        fi
    fi

    write_info $_file
    echo "File saved as \`$_file'"
}

write_info() {
    cat > $1 <<EOF
#
# File automatically generated by @PKGBASE@ @PKGVERSION@
# `date`
#

dfdisk_name="$dfdisk_name"
dfdisk_subdir="$dfdisk_subdir"
dfdisk_type="cd"
EOF
}

ask_info() {
    dfdisk_name=""
    printf "Enter disk name [pkgsrc distfiles `date +%Y%m%d`]: "
    read dfdisk_name
    if [ -z "$dfdisk_name" ]; then
        dfdisk_name="pkgsrc distfiles `date +%Y%m%d`"
    fi

    dfdisk_subdir=""
    while [ -z "$dfdisk_subdir" ]; do
        printf "Enter relative path to distfiles: "
        read dfdisk_subdir
    done
}

# ------------------------------------------------------------------------
# Remove target
# ------------------------------------------------------------------------

do_remove() {
    local _cds _cd _count _ans

    if [ ! -d "$DBDIR" ]; then
        echo "No known disks; nothing to be done."
        return 0
    fi

    _cds="`cd $DBDIR; ls`"
    if [ -z "$_cds" ]; then
        echo "No known disks; nothing to be done."
        return 0
    fi

    if [ ! -w "$DBDIR" ]; then
        err 1 "cannot write to \`$DBDIR'; permission denied?"
    fi

    # Print menu
    echo "List of disks in the database:"
    echo "0 - Exit"
    _count=1
    for _cd in $_cds; do
        . $DBDIR/$_cd/info
        echo "$_count - $dfdisk_name"
        _count=$(($_count + 1))
    done

    # Wait for an answer
    _ans=""
    while [ -z "$_ans" ]; do
        printf "Remove> "
        read _ans
    done

    # Parse answer
    if [ "$_ans" -ne 0 ]; then
        _count=1
        for _cd in $_cds; do
            if [ "$_count" -eq "$_ans" ]; then
                . $DBDIR/$_cd/info
                rm -f $DBDIR/$_cd/contents
                rm -f $DBDIR/$_cd/info
                rmdir $DBDIR/$_cd
                echo "\`$dfdisk_name' removed successfully"
                break
            fi
            _count=$(($_count + 1))
        done
    fi
}

# ------------------------------------------------------------------------
# Main program
# ------------------------------------------------------------------------

usage() {
    echo "usage: $ProgName [-c conf_file] target [target_args]"
    echo
    echo "Available targets:"
    echo "    add              Add a disk to the database interactively."
    echo "    clean            Remove local distfiles known to be in disks."
    echo "    fetch url        Fetch a distfile from a disk or the network."
    echo "    mkinfo [file]    Interactively create a dfdisk.info file."
    echo "    remove           Remove a disk from the database interactively."
    echo
    echo "See dfdisk(1) for more information."
    exit $1
}

show_banner() {
    echo "@PKGBASE@ $ProgVersion ==> $Target"
}

silent_umount() {
    $CD_UMOUNT 2>/dev/null || true
}

args=`getopt c: $*`
if [ $? -ne 0 ]; then
    usage 2
fi
set -- $args
while [ $# -gt 0 ]; do
    case "$1" in
        -c)
            ConfFile="$2"; shift
            ;;
        --)
            shift; break
            ;;
    esac
    shift
done

# Read configuration file
if [ -f "$ConfFile" ]; then
    . $ConfFile
fi

# Set configuration defaults
: ${DBDIR:=/var/db/dfdisk}
: ${CD_DIR:=/cdrom}
: ${CD_MOUNT:="mount ${CD_DIR}"}
: ${CD_UMOUNT:="umount ${CD_DIR}"}
: ${DISTDIR:=/usr/pkgsrc/distfiles}
: ${FTPCMD:="@FTP@"}

if [ $# -eq 0 ]; then
    echo "$ProgName: no target specified"
    usage 2
fi

Target="$1"; shift
TargetArgs="$*"

trap "silent_umount ; echo ; exit 1" INT QUIT

case "$Target" in
    add)
        show_banner
        do_add
        ;;
    clean)
        show_banner
        do_clean
        ;;
    fetch)
        if [ -z "$TargetArgs" ]; then
            usage 2
        fi

        while [ $# -gt 0 -a -z "`echo $1 | egrep '^(ftp|http)://'`" ]; do
            shift
        done
        if [ $# -eq 0 ]; then
            err 1 "the \`fetch' target expects an url"
        fi
        show_banner
        do_fetch $1
        ;;
    mkinfo)
        show_banner
        do_mkinfo $1
        ;;
    remove)
        show_banner
        do_remove
        ;;
    *)
        echo "$ProgName: unknown target \`$Target'"
        usage 2
        ;;
esac

exit
