#!/bin/sh
#
# $NetBSD: sysbuild.sh,v 1.1.1.1 2002/11/28 19:57:29 jmmv Exp $
#
# sysbuild - Automatic NetBSD system builds
# Copyright (c) 2002, Julio Merino <jmmv@netbsd.org>
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

progname=`basename $0`
allargs="$*"
conffile=@SYSBUILD_HOMEDIR@/default.conf

# XXX: This is needed when downgrading privileges with su...
PATH=/bin:/sbin:/usr/bin:/usr/sbin:@PREFIX@/bin:@PREFIX@/sbin

usage() {
    echo "usage: sysbuild [-ms] [-c conf] target [target_arguments]"
    echo
    echo "Flags:"
    echo "    -c conf    Base name of configuration file"
    echo "    -m         Send all output by mail instead of console"
    echo "    -s         Run 'su' to change privileges if needed"
    echo
    echo "Available targets:"
    echo "    build-kernels     Build kernels"
    echo "    build-release     Build a complete release"
    echo "    build-sets        Build system sets only"
    echo "    clean             Clean work directories"
    echo "    clean-srcs        Fix ownerships in source directories"
    echo "    config            Create or edit a configuration file"
    echo "    destroy           Remove all build stuff"
    echo "    etcupdate         Run etcupdate (interactive)"
    echo "    init              Initialize work directories"
    echo "    install-kernel    Install a built kernel"
    echo "    install-sets      Install system sets"
    echo "    update-srcs       Use CVS to update source directories"
}

err() {
    echo "$progname: $*"
    exit 1
}

# --------------------------------------------------------------------
# Checks
# --------------------------------------------------------------------

check_noroot() {
    if [ "`id -un`" != "$USER" ]; then
        if [ "$autosu" = "yes" ]; then
            echo "$progname: downgrading privileges to '$USER'"
            su -l $USER -c "@PREFIX@/bin/sysbuild $allargs"
            if [ $? -ne 0 ]; then
                err "cannot switch privileges; aborting"
            fi
            # XXX: After su, terminate inmediately.
            exit 0
        else
            err "this target must be run as '$USER' user (use the '-s' flag)"
        fi
    fi
}

check_root() {
    if [ `id -u` -ne 0 ]; then
        if [ "$autosu" = "yes" ]; then
            echo "$progname: becoming root"
            su -l root -c "@PREFIX@/bin/sysbuild $allargs"
            if [ $? -ne 0 ]; then
                err "cannot switch privileges; aborting"
            fi
            # XXX: After su, terminate inmediately.
            exit 0
        else
            err "this target must be run as root (use the '-s' flag)"
        fi
    fi
}

check_init() {
    _ok=1
    if [ ! -d $HOMEDIR ]; then _ok=0; fi
    if [ ! -d $BUILDDIR ]; then _ok=0; fi
    if [ ! -d $BUILDDIR/kernel ]; then _ok=0; fi
    if [ ! -d $BUILDDIR/obj ]; then _ok=0; fi
    if [ ! -d $BUILDDIR/root ]; then _ok=0; fi
    if [ ! -d $BUILDDIR/tools ]; then _ok=0; fi
    if [ $_ok -eq 0 ]; then
        err "trees not initialized; use the 'init' target first"
    fi
}

# --------------------------------------------------------------------
# Kernel related functions
# --------------------------------------------------------------------

sysbuild_build_kernels() {
    check_noroot
    check_init

    _confs="$*"
    if [ -z "$_confs" ]; then
        _confs="$KERNCONF"
    fi

    _log=`mktemp /tmp/sysbuild.XXXX`
    if [ "$MAIL_CMDLOG" = "yes" ]; then
        echo "Logging to $_log (will be removed later)"
    else
        echo "Logging to $_log (will NOT be removed later)"
    fi
    echo
    for _k in $_confs; do
        if [ ! -f "$KERNCONFDIR/$_k" ]; then
            echo "No such kernel configuration $_k"
        else
            echo -n "Configuring kernel $_k:"
            mkdir -p $BUILDDIR/kernel/$_k
            config -s $SRCDIR/sys -b $BUILDDIR/kernel/$_k $KERNCONFDIR/$_k >> $_log 2>&1
            if [ $? -ne 0 ]; then
                echo " failed."
            else
                echo " done."
                cd $BUILDDIR/kernel/$_k

                echo -n "Cleaning kernel $_k:"
                make cleandir >> $_log 2>&1
                echo " done."

                echo -n "Depending kernel $_k:"
                make depend >> $_log 2>&1
                if [ $? -ne 0 ]; then
                    echo " failed."
                else
                    echo " done."

                    echo -n "Buildling kernel $_k:"
                    make >> $_log 2>&1
                    if [ $? -ne 0 ]; then
                        echo " failed."
                    else
                        echo " done."
                        echo "Kernel MD5: `md5 netbsd`"
                    fi
                fi
            fi
        fi
        echo
    done

    if [ "$MAIL_CMDLOG" = "yes" ]; then
        echo "Command log follows:"
        cat $_log
        rm -f $_log
    fi
}

sysbuild_install_kernel() {
    check_root
    check_init

    _conf="$*"
    if [ -z "$_conf" ]; then
        _conf="$KERNCONF"
    fi
    _conf=`echo $_conf | cut -d ' ' -f 1`

    if [ ! -f $BUILDDIR/kernel/$_conf/netbsd ]; then
        err "kernel $_conf is not built."
    else
        cd $BUILDDIR/kernel/$_conf
        echo "Kernel MD5: `md5 netbsd`"
        echo "Installing $_conf kernel:"
        make install
    fi
}

# --------------------------------------------------------------------
# Release related functions
# --------------------------------------------------------------------

sysbuild_build_release() {
    check_noroot
    check_init

    _log=`mktemp /tmp/sysbuild.XXXX`

    sysbuild_clean
    if [ "$MAIL_CMDLOG" = "yes" ]; then
        echo "Logging to $_log (will be removed later)"
    else
        echo "Logging to $_log (will NOT be removed later)"
    fi
    echo -n "Building full release:"
    mkdir -p $RELEASEDIR
    cd $SRCDIR
    BSDOBJDIR=$BUILDDIR/obj ./build.sh -T $BUILDDIR/tools -D $BUILDDIR/root -R $RELEASEDIR -U >> $_log 2>&1
    if [ $? -ne 0 ]; then
        echo " failed."
    else
        echo " done."
    fi

    if [ "$MAIL_CMDLOG" != "yes" ]; then
        echo "Command log follows:"
        cat $_log
        rm -f $_log
    fi
}

sysbuild_build_sets() {
    check_noroot
    check_init

    _log=`mktemp /tmp/sysbuild.XXXX`

    sysbuild_clean
    if [ "$MAIL_CMDLOG" = "yes" ]; then
        echo "Logging to $_log (will be removed later)"
    else
        echo "Logging to $_log (will NOT be removed later)"
    fi
    echo -n "Building system:"
    cd $SRCDIR
    BSDOBJDIR=$BUILDDIR/obj ./build.sh -T $BUILDDIR/tools -d -D $BUILDDIR/root -U >> $_log 2>&1
    if [ $? -ne 0 ]; then
        echo " failed."
    else
        echo " done."

        echo -n "Making sets:"
        mkdir -p $RELEASEDIR/binary/sets
        cd $SRCDIR/distrib/sets
        make sets DESTDIR=$BUILDDIR/root RELEASEDIR=$RELEASEDIR UNPRIVED=yes >> $_log 2>&1
        if [ $? -ne 0 ]; then
            echo " failed."
        else
            echo " done."
        fi
    fi

    if [ "$MAIL_CMDLOG" != "yes" ]; then
        echo "Command log follows:"
        cat $_log
        rm -f $_log
    fi
}

sysbuild_install_sets() {
    check_root
    check_init

    for _s in $SETS; do
        echo -n "Installing $_s:"
        if [ ! -f $RELEASEDIR/binary/sets/$_s ]; then
            echo " not built yet"
        else
            cd / && tar xzpf $RELEASEDIR/binary/sets/$_s > /dev/null 2>&1
            if [ $? -ne 0 ]; then
                echo " failed."
            else
                echo " done."
            fi
        fi
    done
    echo
    echo "You MUST now run 'sysbuild etcupdate' by hand to update /etc."
}

# --------------------------------------------------------------------
# Cleanup functions
# --------------------------------------------------------------------

sysbuild_clean() {
    check_noroot
    check_init

    echo -n "Cleaning $BUILDDIR/obj contents:"
    rm -rf $BUILDDIR/obj/*
    echo " done."

    echo -n "Cleaning $BUILDDIR/root contents:"
    rm -rf $BUILDDIR/root/*
    echo " done."

    echo -n "Cleaning $BUILDDIR/tools contents:"
    rm -rf $BUILDDIR/tools/*
    echo " done."
}

sysbuild_destroy() {
    check_root

    echo -n "Destroying $BUILDDIR:"
    rm -rf $BUILDDIR
    echo " done."
}

sysbuild_etcupdate() {
    check_root

    tmp=`mktemp -d /tmp/sysbuild.XXXX`
    if [ ! -f $RELEASEDIR/binary/sets/etc.tgz ]; then
        err "etc.tgz is not yet built."
    fi
    echo -n "Backing up /etc to /etc.old:"
    rm -rf /etc.old
    cp -rf /etc /etc.old > /dev/null 2>&1
    echo " done."
    echo -n "Unpacking etc.tgz:"
    cd $tmp && tar xzpf $RELEASEDIR/binary/sets/etc.tgz > /dev/null 2>&1
    if [ $? -ne 0 ]; then
        echo " failed."
    else
        echo " done."
        etcupdate -b $tmp
        rm -rf $tmp
    fi
}

# --------------------------------------------------------------------
# Initialization and configuration
# --------------------------------------------------------------------

sysbuild_init() {
    check_root

    echo -n "Initializing $HOMEDIR:"
    mkdir -p $HOMEDIR
    chown $USER:$OBJGROUP $HOMEDIR
    echo " done."

    echo -n "Initializing $BUILDDIR:"
    # Make main directory
    mkdir -p $BUILDDIR
    chown $USER:$OBJGROUP $BUILDDIR
    chmod 750 $BUILDDIR
    # Make kernel work area
    mkdir -p $BUILDDIR/kernel
    chown $USER:$OBJGROUP $BUILDDIR/kernel
    chmod 750 $BUILDDIR/kernel
    # Make obj work area
    mkdir -p $BUILDDIR/obj
    chown $USER:$OBJGROUP $BUILDDIR/obj
    chmod 750 $BUILDDIR/obj
    # Make root work area
    mkdir -p $BUILDDIR/root
    chown $USER:$OBJGROUP $BUILDDIR/root
    chmod 750 $BUILDDIR/root
    # Make tools directory
    mkdir -p $BUILDDIR/tools
    chown $USER:$OBJGROUP $BUILDDIR/tools
    chmod 750 $BUILDDIR/tools
    echo " done."
}

sysbuild_config() {
    check_root

    _conf="$1"
    if [ -z "$_conf" ]; then
        _conf="default"
    fi
    _conffile="@SYSBUILD_HOMEDIR@/$_conf.conf"

    if [ ! -f "$_conffile" ]; then
        echo -n "Copying template to $_conffile:"
        cp @EGDIR@/default.conf $_conffile
        chmod 644 $_conffile
        echo " done."
    fi

    if [ -z "$EDITOR" ]; then
        vi $_conffile
    else
        $EDITOR $_conffile
    fi
}

# --------------------------------------------------------------------
# Source related functions
# --------------------------------------------------------------------

sysbuild_clean_srcs() {
    check_root

    _dirs="$*"
    if [ -z "$_dirs" ]; then
        _dirs="$CVSDIRS"
    fi

    for _d in $_dirs; do
        echo -n "Fixing ownerships and permissions of $_d:"
        chown -R $CVSDIRS_OWNER:$CVSDIRS_GROUP $_d
        if [ -n "$CVSDIRS_PERMS" ]; then
            chmod -R $CVSDIRS_PERMS $_d
        fi
        echo " done."
    done
}

sysbuild_update_srcs() {
    check_noroot

    _dirs="$*"
    if [ -z "$_dirs" ]; then
        _dirs="$CVSDIRS"
    fi

    for _d in $_dirs; do
        echo "Updating source tree $_d"
        cd $_d && CVS_RSH=ssh cvs -q -z6 update -dP
        echo
    done
}

# --------------------------------------------------------------------
# Main program
# --------------------------------------------------------------------

# Parse options
args=`getopt c:ms $*`
if [ $? != 0 ]; then
    usage
    exit 1
fi
set -- $args
maillog="no"
autosu="no"
while [ $# -gt 0 ]; do
    case "$1" in
        -c)
            conffile="@SYSBUILD_HOMEDIR@/$2.conf"
            shift
            ;;
        -m)
            maillog="yes"
            maillogfile=`mktemp /tmp/sysbuild.XXXX`
            ;;
        -s)
            autosu="yes"
            ;;
        --)
            shift; break
            ;;
    esac
    shift
done

if [ $# -lt 1 ]; then
    usage
    exit 1
fi

target="$1"
shift

# Read configuration file.
if [ "$target" != "config" -a ! -f $conffile ]; then
    err "configuration file $conffile not found"
elif [ "$target" != "config" ]; then
    . $conffile
fi

# Parse targets.
case $target in
    build-kernels)
        if [ "$maillog" = "yes" ]; then
            sysbuild_build_kernels $* >> $maillogfile
        else
            sysbuild_build_kernels $*
        fi
        ;;
    build-release)
        if [ "$maillog" = "yes" ]; then
            sysbuild_build_release >> $maillogfile
        else
            sysbuild_build_release
        fi
        ;;
    build-sets)
        if [ "$maillog" = "yes" ]; then
            sysbuild_build_sets >> $maillogfile
        else
            sysbuild_build_sets
        fi
        ;;
    clean)
        if [ "$maillog" = "yes" ]; then
            sysbuild_clean >> $maillogfile
        else
            sysbuild_clean
        fi
        ;;
    clean-srcs)
        if [ "$maillog" = "yes" ]; then
            sysbuild_clean_srcs $* >> $maillogfile
        else
            sysbuild_clean_srcs $*
        fi
        ;;
    config)
        sysbuild_config $*
        ;;
    destroy)
        sysbuild_destroy
        ;;
    etcupdate)
        sysbuild_etcupdate
        ;;
    init)
        sysbuild_init
        ;;
    install-kernel)
        if [ "$maillog" = "yes" ]; then
            sysbuild_install_kernel >> $maillogfile
        else
            sysbuild_install_kernel
        fi
        ;;
    install-sets)
        if [ "$maillog" = "yes" ]; then
            sysbuild_install_sets >> $maillogfile
        else
            sysbuild_install_sets
        fi
        ;;
    update-srcs)
        if [ "$maillog" = "yes" ]; then
            sysbuild_update_srcs $* >> $maillogfile 2>&1
        else
            sysbuild_update_srcs $*
        fi
        ;;
    *)
        err "unknown target '$target'"
        ;;
esac

if [ "$maillog" = "yes" ]; then
    mail -s "Output of $target target" $MAILTO < $maillogfile
    rm -f $maillogfile
fi

exit 0
