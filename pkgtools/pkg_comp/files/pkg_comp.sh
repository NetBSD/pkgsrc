#!/bin/sh
#
# $NetBSD: pkg_comp.sh,v 1.13 2003/12/19 09:51:55 jmmv Exp $
#
# pkg_comp - Build packages inside a clean chroot environment
# Copyright (c) 2002, 2003, Julio M. Merino Vidal <jmmv@NetBSD.org>
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

# ----------------------------------------------------------------------
# Default environment values and functions
# ----------------------------------------------------------------------

# USE_GCC3, CFLAGS, CPPFLAGS and CXXFLAGS are ommited from _MKCONF_VARS
# as they require special handling.
_MKCONF_VARS="OBJMACHINE MKOBJDIRS BSDSRCDIR WRKOBJDIR DISTDIR PACKAGES \
              PKG_DEVELOPER CLEANDEPENDS LOCALBASE PKG_SYSCONFBASE \
              CFLAGS CPPFLAGS CXXFLAGS USE_AUDIT_PACKAGES PKGVULNDIR"

_TEMPLATE_VARS="DESTDIR ROOTSHELL COPYROOTCFG BUILD_TARGET DISTRIBDIR SETS \
                SETS_X11 USE_XPKGWEDGE REAL_SRC REAL_SRC_OPTS REAL_PKGSRC \
                REAL_PKGSRC_OPTS REAL_DISTFILES REAL_DISTFILES_OPTS \
                REAL_PACKAGES REAL_PACKAGES_OPTS REAL_PKGVULNDIR \
                NETBSD_RELEASE MOUNT_SCRIPT UMOUNT_SCRIPT SYNC_UMOUNT"

env_clean()
{
    MKCONF_VARS=""
    TEMPLATE_VARS=""
    for var in ${_MKCONF_VARS} ${_TEMPLATE_VARS}; do
        eval $var=\"\"
    done
}

env_setdefaults()
{
    MKCONF_VARS="$MKCONF_VARS ${_MKCONF_VARS}"
    TEMPLATE_VARS="$TEMPLATE_VARS ${_TEMPLATE_VARS}"

    # Default values for variables that will be written to mk.conf.
    : ${OBJMACHINE:=yes}
    : ${MKOBJDIRS:=yes}
    : ${BSDSRCDIR:=/usr/src}
    : ${WRKOBJDIR:=/pkg_comp/obj/pkgsrc}
    : ${DISTDIR:=/pkg_comp/distfiles}
    : ${PACKAGES:=/pkg_comp/packages}
    : ${PKG_DEVELOPER:=yes}
    : ${CLEANDEPENDS:=yes}
    : ${LOCALBASE:=/usr/pkg}
    : ${PKG_SYSCONFDIR:=/usr/pkg/etc}
    : ${CFLAGS:=}
    : ${CPPFLAGS:=}
    : ${CXXFLAGS:=}
    : ${USE_GCC3:=no}
    : ${USE_AUDIT_PACKAGES:=yes}
    : ${PKGVULNDIR:=/usr/pkg/share}

    # Default values for global variables used in the script.
    : ${DESTDIR:=/var/chroot/pkg_comp/default}
    : ${ROOTSHELL:=/bin/ksh}
    : ${COPYROOTCFG:=no}
    : ${BUILD_TARGET:=package}
    : ${DISTRIBDIR:=/var/pub/NetBSD}
    : ${SETS:=base.tgz comp.tgz etc.tgz text.tgz}
    : ${SETS_X11:=xbase.tgz xcomp.tgz xcontrib.tgz xfont.tgz xmisc.tgz xserver.tgz}
    : ${USE_XPKGWEDGE:=yes}
    : ${REAL_SRC:=/usr/src}
    : ${REAL_SRC_OPTS:=-t null -o ro}
    : ${REAL_PKGSRC:=/usr/pkgsrc}
    : ${REAL_PKGSRC_OPTS:=-t null -o ro}
    : ${REAL_DISTFILES:=/usr/pkgsrc/distfiles}
    : ${REAL_DISTFILES_OPTS:=-t null -o rw}
    : ${REAL_PACKAGES:=/usr/pkgsrc/packages}
    : ${REAL_PACKAGES_OPTS:=-t null -o rw}
    : ${REAL_PKGVULNDIR:=/usr/pkgsrc/distfiles}
    : ${NETBSD_RELEASE:=no}
    : ${MOUNT_SCRIPT:=}
    : ${UMOUNT_SCRIPT:=}
    : ${SYNC_UMOUNT:=no}
}

# ----------------------------------------------------------------------
# Misc functions
# ----------------------------------------------------------------------

err()
{
    echo "$ProgName: $1"
    exit 1
}

usage()
{
    echo "usage: $ProgName [-(c|C) conf_file] [-n] target [pkg_names]"
    exit 1
}

copy_vulnerabilities()
{
    if [ "$USE_AUDIT_PACKAGES" = "yes" ]; then
        echo "PKG_COMP ==> Installing new \`pkg-vulnerabilities' file"
        if [ ! -f "$REAL_PKGVULNDIR/pkg-vulnerabilities" ]; then
            echo "$REAL_PKGVULNDIR/pkg-vulnerabilities not found."
        else
            mkdir -p $DESTDIR/$PKGVULNDIR
            cp $REAL_PKGVULNDIR/pkg-vulnerabilities $DESTDIR/$PKGVULNDIR
        fi
    fi
}

# ----------------------------------------------------------------------
# Filesystem functions
# ----------------------------------------------------------------------

fsmount()
{
    printf "PKG_COMP ==> Mounting chroot filesystems:"
    if [ -f $fsstate ]; then
        count=`cat $fsstate`
        count=$(($count + 1))
        echo "$count" > $fsstate
        echo " already mounted."
        return
    else
        echo "1" > $fsstate
    fi

    if [ -n "$REAL_SRC" ]; then
        if [ ! -d "$REAL_SRC" ]; then
            echo " failed."
            fsumount
            err "REAL_SRC $REAL_SRC disappeared"
        fi
        mount $REAL_SRC_OPTS $REAL_SRC $DESTDIR/usr/src
    fi

    if [ -n "$REAL_PKGSRC" ]; then
        if [ ! -d "$REAL_PKGSRC" ]; then
            echo " failed."
            fsumount
            err "REAL_PKGSRC $REAL_PKGSRC disappeared"
        fi
        mount $REAL_PKGSRC_OPTS $REAL_PKGSRC $DESTDIR/usr/pkgsrc
    fi

    if [ -n "$REAL_DISTFILES" ]; then
        if [ ! -d "$REAL_DISTFILES" ]; then
            echo " failed."
            fsumount
            err "REAL_DISTFILES $REAL_DISTFILES disappeared"
        fi
        mount $REAL_DISTFILES_OPTS $REAL_DISTFILES $DESTDIR/pkg_comp/distfiles
    fi

    if [ -n "$REAL_PACKAGES" ]; then
        if [ ! -d "$REAL_PACKAGES" ]; then
            echo " failed."
            fsumount
            err "REAL_PACKAGES $REAL_PACKAGES disappeared"
        fi
        mount $REAL_PACKAGES_OPTS $REAL_PACKAGES $DESTDIR/pkg_comp/packages
    fi

    touch $fsstate
    echo " done."

    if [ -n "$MOUNT_SCRIPT" -a -x "$MOUNT_SCRIPT" ]; then
        echo "PKG_COMP ==> Executing mount script."
        $MOUNT_SCRIPT $DESTDIR mount
    fi
}

fsumount()
{
    msg="PKG_COMP ==> Unmounting chroot filesystems:"

    if [ ! -f $fsstate ]; then
        echo "$msg none mounted."
        return
    fi

    count=`cat $fsstate`
    if [ $count -gt 1 ]; then
        count=$(($count - 1))
        echo "$count" > $fsstate
        echo "$msg still in use."
        return
    fi

    if [ -n "$UMOUNT_SCRIPT" -a -x "$UMOUNT_SCRIPT" ]; then
        echo "PKG_COMP ==> Executing umount script."
        $UMOUNT_SCRIPT $DESTDIR umount
    fi

    printf "$msg"

    fsfailed=no

    if [ -n "$REAL_SRC" -a -d "$REAL_SRC" ]; then
        umount $DESTDIR/usr/src
        if [ $? != 0 ]; then fsfailed=yes; fi
    fi

    if [ -n "$REAL_PKGSRC" -a -d "$REAL_PKGSRC" ]; then
        umount $DESTDIR/usr/pkgsrc
        if [ $? != 0 ]; then fsfailed=yes; fi
    fi

    if [ -n "$REAL_DISTFILES" -a -d "$REAL_DISTFILES" ]; then
        umount $DESTDIR/pkg_comp/distfiles
        if [ $? != 0 ]; then fsfailed=yes; fi
    fi

    if [ -n "$REAL_PACKAGES" -a -d "$REAL_PACKAGES" ]; then
        umount $DESTDIR/pkg_comp/packages
        if [ $? != 0 ]; then fsfailed=yes; fi
    fi

    echo " done."

    if [ "$SYNC_UMOUNT" != "no" ]; then
        printf "Syncing: 1"
        sync ; sleep 1
        printf " 2"
        sync ; sleep 1
        printf " 3"
        sync ; sleep 1
        echo " done."
    fi

    if [ "$fsfailed" = "yes" ]; then
        err "FATAL: failed to umount all filesystems"
    else
        rm $fsstate
    fi
}

# ----------------------------------------------------------------------
# maketemplate target
# ----------------------------------------------------------------------

pkg_maketemplate()
{
    if [ -f "$conffile" ]; then
        err "$conffile already exists"
    fi

    mkdir -p $confdir
    cat > $conffile <<EOF
# -*- sh -*-
#
# pkg_comp - configuration file
# See pkg_comp(8) for a detailed description of each variable.
#

EOF

    echo "# Variables used internally by pkg_comp." >> $conffile
    for var in $TEMPLATE_VARS; do
        eval val=\""\$$var"\"
        echo "$var=\"$val\"" >> $conffile
    done

    echo >> $conffile
    echo "# Default variables written to the generated mk.conf." >> $conffile
    for var in $MKCONF_VARS; do
        eval val=\""\$$var"\"
        echo "$var=\"$val\"" >> $conffile
    done

    echo "pkg_comp: $conffile created.  Edit the file by hand now."
}

# ----------------------------------------------------------------------
# makeroot target
# ----------------------------------------------------------------------

pkg_makeroot()
{
    # Check for directories that will be null mounted.
    if [ -n "$REAL_SRC" -a ! -d "$REAL_SRC" ]; then
        err "REAL_SRC $REAL_SRC does not exist"
    fi

    if [ -n "$REAL_PKGSRC" -a ! -d "$REAL_PKGSRC" ]; then
        err "REAL_PKGSRC $REAL_PKGSRC does not exist"
    fi

    if [ -n "$REAL_DISTFILES" -a ! -d "$REAL_DISTFILES" ]; then
        err "REAL_DISTFILES $REAL_DISTFILES does not exist"
    fi

    if [ -n "$REAL_PACKAGES" -a ! -d "$REAL_PACKAGES" ]; then
        err "REAL_PACKAGES $REAL_PACKAGES does not exist"
    fi

    # Check for required directories.
    if [ ! -d $DISTRIBDIR ]; then
        err "DISTRIBDIR $DISTRIBDIR does not exist"
    fi

    if [ -d $DESTDIR ]; then
        err "DESTDIR $DESTDIR already exists"
    fi

    if [ "$SETS_X11" = "no" ]; then
        allsets="$SETS"
    else
        allsets="$SETS $SETS_X11"
    fi

    for s in $allsets; do
        if [ ! -f $DISTRIBDIR/binary/sets/$s ]; then
            err "$DISTRIBDIR/binary/sets/$s does not exist"
        fi
    done

    mkdir -p $DESTDIR
    cd $DESTDIR

    printf "Unpacking sets:"
    for s in $allsets; do
        printf " $s"
        tar xzpf $DISTRIBDIR/binary/sets/$s
    done
    echo

    printf "Making device nodes:"
    cd $DESTDIR/dev
    ./MAKEDEV all
    cd $DESTDIR
    echo " done."

    printf "Setting root's environment:"
    chroot $DESTDIR chpass -s $ROOTSHELL
    if [ "$COPYROOTCFG" = "yes" ]; then
        cp /root/.* $DESTDIR/root 2>&1 | > /dev/null
    fi
    echo " done."

    printf "Setting up initial configuration:"

    mkdir -p $DESTDIR/usr/src
    mkdir -p $DESTDIR/usr/pkgsrc
    mkdir -p $DESTDIR/pkg_comp/distfiles
    mkdir -p $DESTDIR/pkg_comp/packages
    mkdir -p $DESTDIR/pkg_comp/tmp
    mkdir -p $DESTDIR/pkg_comp/obj/pkgsrc

    # Set sh configuration
    echo "umask 022" >> $DESTDIR/etc/profile
    echo "ENV=/etc/shrc" >> $DESTDIR/etc/profile
    echo "export PS1=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/shrc
    echo "set -o emacs" >> $DESTDIR/etc/shrc

    # Set csh configuration
    echo "umask 022" >> $DESTDIR/etc/csh.login
    echo "set prompt=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/csh.login
    echo "set prompt=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/csh.cshrc

    cp /etc/resolv.conf $DESTDIR/etc/resolv.conf

    makeroot_mkconf

    echo " done."
 
    # From now on, filesystems may be mounted, so we need to trap
    # signals to umount them.
    trap "echo \"*** Process aborted ***\" ; fsumount ; exit 1" INT QUIT

    check_pkg_install

    if [ "$USE_AUDIT_PACKAGES" = "yes" ]; then
        pkg_build security/audit-packages
    fi

    if [ "$NETBSD_RELEASE" != "no" ]; then
        BUILD_TARGET=install pkg_build pkgtools/libkver
        echo "LD_PRELOAD=${LOCALBASE}/lib/libkver.so; export LD_PRELOAD" >> $DESTDIR/etc/shrc
        echo "setenv LD_PRELOAD ${LOCALBASE}/lib/libkver.so" >> $DESTDIR/etc/csh.login
        echo "setenv LD_PRELOAD ${LOCALBASE}/lib/libkver.so" >> $DESTDIR/etc/csh.cshrc
        ln -s "$NETBSD_RELEASE" $DESTDIR/libkver_osrelease
    fi

    if [ "$USE_GCC3" = "yes" ]; then
        if [ -z "`echo $MAKE_PACKAGES $INSTALL_PACKAGES | grep gcc3`" ]; then
            AVOID_GCC3=yes pkg_build lang/gcc3
        fi
    fi

    if [ "$SETS_X11" != "no" ]; then
        makeroot_xpkgwedge
        pkg_build pkgtools/x11-links
    fi

    if [ "$nflag" = "no" -a -n "$INSTALL_PACKAGES" ]; then
        pkg_install $INSTALL_PACKAGES
    fi

    if [ "$nflag" = "no" -a -n "$MAKE_PACKAGES" ]; then
        pkg_build $MAKE_PACKAGES
    fi
}

makeroot_mkconf()
{
    file="$DESTDIR/etc/mk.conf"

    cat >> $file <<EOF
#
# /etc/mk.conf
# File automatically generated by pkg_comp on `date`
#
.ifdef BSD_PKG_MK

EOF

    for var in $MKCONF_VARS; do
        eval val=\""\$$var"\"
        if [ -n "$val" ]; then
            echo "$var ?= $val" >> $file
        fi
    done

    if [ -n "$EXTRAMK" ]; then
        if [ ! -f "$EXTRAMK" ]; then
            err "Cannot find $EXTRAMK"
        else
            cat $EXTRAMK >> $file
        fi
    fi

    if [ "$USE_AUDIT_PACKAGES" != "yes" ]; then
        echo "ALLOW_VULNERABLE_PACKAGES ?= YES" >> $file
    fi

    if [ "$USE_GCC3" = "yes" ]; then
        cat >>$file <<EOF
.if !defined(AVOID_GCC3) && exists(/usr/pkg/share/examples/gcc-3.3/mk.conf)
USE_GCC3 = yes
CFLAGS += $CFLAGS
CPPFLAGS += $CPPFLAGS
CXXFLAGS += $CXXFLAGS
.include "/usr/pkg/share/examples/gcc-3.3/mk.conf"
.endif
EOF
    else
        cat >>$file <<EOF
CFLAGS += $CFLAGS
CPPFLAGS += $CPPFLAGS
CXXFLAGS += $CXXFLAGS

.endif # BSD_PKG_MK
EOF
    fi
}

makeroot_xpkgwedge()
{
    if [ -n "$SETS_X11" ]; then
        if [ $USE_XPKGWEDGE = "yes" ]; then
            pkg_build "pkgtools/xpkgwedge"
            echo "export XAPPLRESDIR=${LOCALBASE}/lib/X11/app-defaults" >> $DESTDIR/etc/profile
            echo "setenv XAPPLRESDIR ${LOCALBASE}/lib/X11/app-defaults" >> $DESTDIR/etc/csh.login
        fi
    fi
}

# ----------------------------------------------------------------------
# build target
# ----------------------------------------------------------------------

pkg_build()
{
    pkgs="$*"

    # Check if all packages exist
    invalid=""
    for p in $pkgs; do
        if [ ! -d $REAL_PKGSRC/$p ]; then
            invalid="$invalid $p"
        fi
    done
    if [ -n "$invalid" ]; then
        err "invalid packages:$invalid"
    fi

    check_pkg_install    # executes copy_vulnerabilities too

    # Build them
    fsmount
    failed=""
    for p in $pkgs; do
        echo "PKG_COMP ==> Building and installing $p"
        prefix=`mktemp $DESTDIR/pkg_comp/tmp/pkg_comp-XXXX`
        rm $prefix
        script="$prefix.sh"
        statfile="$prefix.stat"
        cat > $script <<EOF
#!/bin/sh
cd /usr/pkgsrc/$p
make $BUILD_TARGET
if [ \$? != 0 ]; then
    touch /pkg_comp/tmp/`basename $statfile`
fi
make clean
EOF
        chmod +x $script
        chroot $DESTDIR /pkg_comp/tmp/`basename $script`
        rm $script
        if [ -f $statfile ]; then
            failed="$failed $p"
            rm $statfile
        fi
    done
    fsumount
    if [ -n "$failed" ]; then
        echo "PKG_COMP ==> Build error summary"
        echo "Build failed for:"
        for p in $failed; do
            echo "    $p"
        done
    fi
}

check_pkg_install()
{
    copy_vulnerabilities

    echo "PKG_COMP ==> Checking that pkg_install is up to date"
    fsmount
    script=`mktemp $DESTDIR/pkg_comp/tmp/pkg_comp-XXXX`.sh
    cat > $script <<EOF
#!/bin/sh
cd /usr/pkgsrc/pkgtools/pkg_comp
fail=\$(make show-var VARNAME=PKG_FAIL_REASON)
if echo \$fail | grep "package tools need to be updated" >/dev/null; then
    echo "PKG_COMP ==> pkg_install is out of date; rebuilding"
    cd /usr/pkgsrc/pkgtools/pkg_install
    make && make install && make clean
fi
EOF
    chmod +x $script
    chroot $DESTDIR /pkg_comp/tmp/`basename $script`
    rm $script
    fsumount
}

# ----------------------------------------------------------------------
# install target
# ----------------------------------------------------------------------

pkg_install()
{
    pkgs="$*"

    if [ -z "$REAL_PACKAGES" ]; then
        err "REAL_PACKAGES is not set"
    fi

    copy_vulnerabilities

    fsmount
    failed=""
    for p in $pkgs; do
        if [ -f $DESTDIR/pkg_comp/packages/All/$p ]; then
            echo "PKG_COMP ==> Installing binary package: $p"
            stat=$DESTDIR/pkg_comp/tmp/install.sh
            cat >> $stat <<EOF
#!/bin/sh
cd /pkg_comp/packages/All
pkg_add $p
EOF
            chmod +x $stat
            chroot $DESTDIR /pkg_comp/tmp/install.sh
            rm $stat
        else
            failed="$failed $p"
        fi
    done
    fsumount
    if [ -n "$failed" ]; then
        echo "Installation failed for:$failed"
    fi
}

# ----------------------------------------------------------------------
# chroot target
# ----------------------------------------------------------------------

pkg_chroot()
{
    if [ ! -d $DESTDIR ]; then
        err "$DESTDIR does not exist"
    fi

    copy_vulnerabilities

    fsmount
    echo "PKG_COMP ==> Entering chroot: $DESTDIR"
    if [ $# -eq 0 ]; then
        ENV=/etc/shrc chroot $DESTDIR $ROOTSHELL
    else
        ENV=/etc/shrc chroot $DESTDIR $*
    fi
    echo
    fsumount
}

# ----------------------------------------------------------------------
# removeroot target
# ----------------------------------------------------------------------

pkg_removeroot()
{
    if [ -f $fsstate ]; then
        err "filesystems may still be mounted; cannot remove"
    fi
    printf "PKG_COMP ==> Removing chroot:"
    rm -rf $DESTDIR
    echo " done."
}

# ----------------------------------------------------------------------
# Main program
# ----------------------------------------------------------------------

confdir="$HOME/pkg_comp"

# Parse options
args=`getopt c:C:n $*`
if [ $? != 0 ]; then
    usage
fi
set -- $args
conffile=
nflag=no
while [ $# -gt 0 ]; do
    case "$1" in
        -c)
	    if [ -n "$conffile" ]; then
                usage
            fi
            conffile="$confdir/$2.conf"
            shift
            ;;
        -C)
            if [ -n "$conffile" ]; then
                usage
            fi
            conffile="$2"
            shift
            ;;
        -n)
            nflag=yes
            ;;
        --)
            shift; break
            ;;
    esac
    shift
done

if [ $# -lt 1 ]; then
    usage
fi

if [ -z "$conffile" ]; then
    conffile="$confdir/default.conf"
fi

target="$1"
shift
args="$*"

readconf()
{
    if [ -f $conffile ]; then
        if [ `id -u` -ne 0 ]; then
            err "must be run as root"
        fi
        echo "Reading config file: $conffile"
        env_clean
        . $conffile
        env_setdefaults
    else
        err "$conffile does not exist"
    fi

    fsstate="$DESTDIR/pkg_comp/tmp/mount.stat"
}

checkroot()
{
    if [ ! -d "$DESTDIR" ]; then
        err "chroot not initialized; use makeroot first."
    fi
    if [ "$DESTDIR" = "/" ]; then
        err "DESTDIR cannot be /"
    fi

    # From now on, filesystems may be mounted, so we need to trap
    # signals to umount them.
    trap "echo \"*** Process aborted ***\" ; fsumount ; exit 1" INT QUIT
}

case "$target" in
    maketemplate)
        env_clean
        env_setdefaults
        pkg_maketemplate
        exit 0
        ;;
    makeroot)
        readconf
        pkg_makeroot
        exit 0
        ;;
    build)
        readconf
        checkroot
        pkg_build $args
        exit 0
        ;;
    install)
        readconf
        checkroot
        pkg_install $args
        exit 0
        ;;
    chroot)
        readconf
        checkroot
        pkg_chroot $args
        exit 0
        ;;
    removeroot)
        readconf
        checkroot
        pkg_removeroot
        ;;
    auto)
        readconf
        BUILD_TARGET="package"
        if [ -z "$REAL_PACKAGES" ]; then
            err "this is useless without REAL_PACKAGES"
        fi
        if [ -z "$MAKE_PACKAGES" -a -z "$args" ]; then
            err "this is useless without MAKE_PACKAGES nor package names"
        fi
        pkg_makeroot
        checkroot
        if [ -n "$args" ]; then
            pkg_build $args
        fi
        pkg_removeroot
        ;;
    *)
        err "unknown target \`$target'"
        ;;
esac

exit 0

