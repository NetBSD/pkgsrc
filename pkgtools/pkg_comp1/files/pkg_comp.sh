#!/bin/sh
#
# $NetBSD: pkg_comp.sh,v 1.2 2020/04/23 11:28:09 sborrill Exp $
#
# pkg_comp - Build packages inside a clean chroot environment
# Copyright (c) 2002, 2003, 2004, 2005 Julio M. Merino Vidal <jmmv@NetBSD.org>
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
_MKCONF_VARS="WRKDIR_BASENAME MKOBJDIRS BSDSRCDIR WRKOBJDIR DISTDIR PACKAGES \
              PKG_DEVELOPER CLEANDEPENDS LOCALBASE PKG_SYSCONFBASE \
              CFLAGS CPPFLAGS CXXFLAGS USE_AUDIT_PACKAGES PKGVULNDIR \
              PKGSRC_COMPILER \
              LIBKVER_STANDALONE_PREFIX PKG_DBDIR"

_TEMPLATE_VARS="DESTDIR ROOTSHELL BUILD_PKG_COMP_TARGET COPYROOTCFG DISTRIBDIR \
		SETS SETS_X11 REAL_SRC REAL_SRC_OPTS REAL_PKGSRC \
                REAL_PKGSRC_OPTS REAL_DISTFILES REAL_DISTFILES_OPTS \
                REAL_PACKAGES REAL_PACKAGES_OPTS REAL_PKGVULNDIR \
                NETBSD_RELEASE MAKEROOT_HOOKS MOUNT_HOOKS UMOUNT_HOOKS \
                SYNC_UMOUNT AUTO_TARGET AUTO_PACKAGES BUILD_PACKAGES \
                REAL_CCACHE LIBKVER_STANDALONE_PREFIX GENERATE_PKG_SUMMARY"

_BUILD_RESUME=

# env_clean
#
#   Sets all variables that may appear in the config file to the null
#   string, so that we know the environment is in a consistent state.
#
env_clean()
{
    MKCONF_VARS=""
    TEMPLATE_VARS=""
    for var in ${_MKCONF_VARS} ${_TEMPLATE_VARS}; do
        eval $var=\"\"
    done
}

# env_setdefaults
#
#   Sets several reasonable defaults for many variables we will use.
#   Also checks for deprecated variables and warns the user about them.
#   To be called after reading the configuration file.
#
env_setdefaults()
{
    MKCONF_VARS="$MKCONF_VARS ${_MKCONF_VARS}"
    TEMPLATE_VARS="$TEMPLATE_VARS ${_TEMPLATE_VARS}"

    # Default values for variables that will be written to mk.conf.
    : ${WRKDIR_BASENAME:=default}
    : ${MKOBJDIRS:=yes}
    : ${BSDSRCDIR:=/usr/src}
    : ${WRKOBJDIR:=/pkg_comp/obj/pkgsrc}
    : ${DISTDIR:=/pkg_comp/distfiles}
    : ${PACKAGES:=/pkg_comp/packages}
    : ${PKG_DEVELOPER:=yes}
    : ${CLEANDEPENDS:=yes}
    : ${LOCALBASE:=/usr/pkg}
    : ${PKG_SYSCONFBASE:=/usr/pkg/etc}
    : ${CFLAGS:=}
    : ${CPPFLAGS:=}
    : ${CXXFLAGS:=}
    : ${USE_GCC3:=no}
    : ${USE_AUDIT_PACKAGES:=yes}
    : ${PKGVULNDIR:=/usr/pkg/share}
    : ${PKGSRC_COMPILER:=gcc}
    : ${PKG_DBDIR:=/var/db/pkg}

    # Default values for global variables used in the script.
    : ${DISTRIB_EXT:=tgz}
    : ${DESTDIR:=/var/chroot/pkg_comp/default}
    : ${ROOTSHELL:=/bin/ksh}
    : ${COPYROOTCFG:=no}
    : ${AUTO_TARGET:=package}
    : ${BUILD_PKG_COMP_TARGET:=package}
    : ${DISTRIBDIR:=/var/pub/NetBSD}
    : ${SETS:=base.${DISTRIB_EXT} comp.${DISTRIB_EXT} etc.${DISTRIB_EXT} kern-GENERIC.${DISTRIB_EXT} text.${DISTRIB_EXT}}
    : ${SETS_X11:=xbase.${DISTRIB_EXT} xcomp.${DISTRIB_EXT} xetc.${DISTRIB_EXT} xfont.${DISTRIB_EXT} xserver.${DISTRIB_EXT}}
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
    : ${LIBKVER_STANDALONE_PREFIX:=/libkver}
    : ${MAKEROOT_HOOKS:=}
    : ${MOUNT_HOOKS:=}
    : ${UMOUNT_HOOKS:=}
    : ${SYNC_UMOUNT:=no}
    : ${REAL_CCACHE:=}
    : ${GENERATE_PKG_SUMMARY:=yes}

    if [ -n "${MAKE_PACKAGES}" ]; then
        warn "MAKE_PACKAGES is deprecated; use {AUTO,BUILD}_PACKAGES instead."
        : ${AUTO_PACKAGES:=${MAKE_PACKAGES}}
        : ${BUILD_PACKAGES:=${MAKE_PACKAGES}}
    fi

    if [ -n "${MOUNT_SCRIPT}" ]; then
        warn "MOUNT_SCRIPT is deprecated; use MOUNT_HOOKS instead."
        : ${MOUNT_HOOKS:=${MOUNT_SCRIPT}}
    fi

    if [ -n "${UMOUNT_SCRIPT}" ]; then
        warn "UMOUNT_SCRIPT is deprecated; use UMOUNT_HOOKS instead."
        : ${UMOUNT_HOOKS:=${UMOUNT_SCRIPT}}
    fi
}

# ----------------------------------------------------------------------
# Misc functions
# ----------------------------------------------------------------------

# err msg
#
#   Shows the given error message and exit.
#
err()
{
    echo "$ProgName: $1" 1>&2
    exit 1
}

# warn msg
#
#   Shows the given warning message.
#
warn()
{
    echo "$ProgName: $1" 1>&2
}

# usage
#
#   Shows an usage message and exits.
#
usage()
{
    echo "usage: $ProgName [-(c|C) conf_file] [-Nn] target [pkg_names]" 1>&2
    exit 1
}

# copy_vulnerabilities
#
#   If USE_AUDIT_PACKAGES is set to 'yes', this function copies the
#   system-wide pkg-vulnerabilities file inside the sandbox.
#
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

# init_script filename
#
#   Create a script that will be used within the sandbox and write some
#   common content to it.
#
init_script()
{
    rm -f $1
    cat >$1 <<EOF
#!/bin/sh
# Generated by pkg_comp on `date`

if [ -f ${LIBKVER_STANDALONE_PREFIX}/lib/libkver.so ]; then
    LD_PRELOAD=${LIBKVER_STANDALONE_PREFIX}/lib/libkver.so; export LD_PRELOAD
fi

EOF
}

# ----------------------------------------------------------------------
# Filesystem functions
# ----------------------------------------------------------------------

# fsmount
#
#   Mounts all sandboxed filesystems, if they are not mounted yet.
#
fsmount()
{
    echo "PKG_COMP ==> Mounting sandboxed filesystems"
    if [ -f $fsstate ]; then
        count=`cat $fsstate`
        count=$(($count + 1))
        echo "$count" > $fsstate
        echo "Already mounted (maybe by another pkg_comp process?)"
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

    if [ -n "${REAL_CCACHE}" ]; then
        if [ ! -d "${REAL_CCACHE}" ]; then
            echo " failed."
            fsumount
            err "REAL_CCACHE ${REAL_CCACHE} disappeared"
        fi
        mount -t null -o rw ${REAL_CCACHE} ${DESTDIR}/pkg_comp/ccache
    fi

    touch $fsstate

    if [ -n "${MOUNT_HOOKS}" ]; then
        echo "Executing mount hooks."
        for h in ${MOUNT_HOOKS}; do
            ${h} ${DESTDIR} mount
        done
    fi
}

# fsumount
#
#   Unmounts all sandboxed filesystems, if they are not in use any more.
#
fsumount()
{
    echo "PKG_COMP ==> Unmounting sandboxed filesystems"

    if [ ! -f $fsstate ]; then
        echo "None mounted."
        return
    fi

    count=`cat $fsstate`
    if [ $count -gt 1 ]; then
        count=$(($count - 1))
        echo "$count" > $fsstate
        echo "Still in use (maybe by another pkg_comp process?)"
        return
    fi

    if [ -n "${UMOUNT_HOOKS}" ]; then
        echo "Executing umount hooks."
        for h in ${UMOUNT_HOOKS}; do
            ${h} ${DESTDIR} umount
        done
    fi

    fsfailed=no

    if [ -n "$REAL_SRC" -a -d "$REAL_SRC" ]; then
        umount $DESTDIR/usr/src || fsfailed=yes
    fi

    if [ -n "$REAL_PKGSRC" -a -d "$REAL_PKGSRC" ]; then
        umount $DESTDIR/usr/pkgsrc || fsfailed=yes
    fi

    if [ -n "$REAL_DISTFILES" -a -d "$REAL_DISTFILES" ]; then
        umount $DESTDIR/pkg_comp/distfiles || fsfailed=yes
    fi

    if [ -n "$REAL_PACKAGES" -a -d "$REAL_PACKAGES" ]; then
        umount $DESTDIR/pkg_comp/packages || fsfailed=yes
    fi

    if [ -n "${REAL_CCACHE}" -a -d "${REAL_CCACHE}" ]; then
        umount ${DESTDIR}/pkg_comp/ccache || fsfailed=yes
    fi

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

# pkg_maketemplate
#
#   Generates a sample configuration file based on the list of variables
#   given in TEMPLATE_VARS and MKCONF_VARS.
#
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
    for var in `echo $TEMPLATE_VARS | tr ' ' '\n' | sort`; do
        eval val=\""\$$var"\"
        echo "$var=\"$val\"" >> $conffile
    done

    echo >> $conffile
    echo "# Default variables written to the generated mk.conf." >> $conffile
    for var in `echo $MKCONF_VARS | tr ' ' '\n' | sort`; do
        eval val=\""\$$var"\"
        echo "$var=\"$val\"" >> $conffile
    done

    echo "pkg_comp: $conffile created.  Edit the file by hand now."
}

# ----------------------------------------------------------------------
# makeroot target
# ----------------------------------------------------------------------

# pkg_makeroot
#
#   The 'makeroot' target.  This creates a new sandbox and then issues
#   some stuff to be called only when using this specific target.
#
pkg_makeroot()
{
    makeroot

    [ "$nflag" = "no" -a -n "$INSTALL_PACKAGES" ] &&
        pkg_install $INSTALL_PACKAGES

    if [ "$nflag" = "no" -a -n "$BUILD_PACKAGES" ]; then
        for pkg in $BUILD_PACKAGES; do
            build_and_install $pkg
        done
    fi
}

# makeroot
#
#   Creates a new sandbox.  This is independent from 'makeroot' and
#   'auto' targets.
#
makeroot()
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

    if echo ${PKGSRC_COMPILER} | grep ccache >/dev/null 2>&1 && \
        [ -z "${REAL_CCACHE}" ]; then
        warn "PKGSRC_COMPILER contains 'ccache' but REAL_CCACHE is unset"
    elif [ -n "${REAL_CCACHE}" -a ! -d "${REAL_CCACHE}" ]; then
        err "REAL_CCACHE ${REAL_CCACHE} does not exist"
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

    echo "PKG_COMP ==> Creating sandbox \`${DESTDIR}'"

    mkdir -p $DESTDIR
    cd $DESTDIR

    for s in $allsets; do
        echo "Extracting $s..."
        tar xzpf $DISTRIBDIR/binary/sets/$s
    done

    [ -f ${DESTDIR}/netbsd ] || touch ${DESTDIR}/netbsd

    echo "Making device nodes..."
    cd $DESTDIR/dev
    ./MAKEDEV all
    cd $DESTDIR

    echo "Setting root's environment..."
    chroot $DESTDIR chpass -s $ROOTSHELL
    if [ "$COPYROOTCFG" = "yes" ]; then
        cp /root/.* $DESTDIR/root >/dev/null 2>&1
    fi
    if [ -n "${REAL_CCACHE}" ]; then
        # This is a workaround for older versions of ccache.mk that do not
        # pass the CCACHE_DIR variable down to ccache.
        ( cd ${DESTDIR}/root && ln -fs ../pkg_comp/ccache .ccache )
    fi

    echo "Setting up initial configuration..."

    mkdir -p $DESTDIR/usr/src
    mkdir -p $DESTDIR/usr/pkgsrc
    mkdir -p $DESTDIR/pkg_comp/distfiles
    mkdir -p $DESTDIR/pkg_comp/packages
    mkdir -p $DESTDIR/pkg_comp/tmp
    mkdir -p $DESTDIR/pkg_comp/obj/pkgsrc
    [ -n "${REAL_CCACHE}" ] && mkdir -p ${DESTDIR}/pkg_comp/ccache
    ( cd $DESTDIR && ln -s pkg_comp p )

    # Set sh configuration
    echo "umask 022" >> $DESTDIR/etc/profile
    echo "ENV=/etc/shrc" >> $DESTDIR/etc/profile
    echo "export PS1=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/shrc
    echo "set -o emacs" >> $DESTDIR/etc/shrc
    echo "export PKG_DBDIR=\"${PKG_DBDIR}\"" >> ${DESTDIR}/etc/shrc

    # Set csh configuration
    echo "umask 022" >> $DESTDIR/etc/csh.login
    echo "set prompt=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/csh.login
    echo "set prompt=\"pkg_comp:`basename $conffile`# \"" >> $DESTDIR/etc/csh.cshrc
    echo "setenv PKG_DBDIR \"${PKG_DBDIR}\"" >> ${DESTDIR}/etc/csh.cshrc

    cp /etc/resolv.conf $DESTDIR/etc/resolv.conf

    makeroot_mkconf

    echo "PKG_DBDIR=${PKG_DBDIR}" >> ${DESTDIR}/etc/pkg_install.conf

    # From now on, filesystems may be mounted, so we need to trap
    # signals to umount them.
    trap "echo \"*** Process aborted ***\" ; fsumount ; exit 1" INT QUIT

    makeroot_libkver

    if [ "$USE_GCC3" = "yes" -a "$Nflag" = "no" ]; then
        if [ -z "`echo $BUILD_PACKAGES $INSTALL_PACKAGES | grep gcc3`" ]; then
            AVOID_GCC3=yes build_and_install lang/gcc3
        fi
    fi

    makeroot_x11

    if [ -n "${MAKEROOT_HOOKS}" ]; then
        echo "Executing makeroot hooks."
        for h in ${MAKEROOT_HOOKS}; do
            ${h} ${DESTDIR} makeroot
        done
    fi
}

# makeroot_mkconf
#
#   Generates a mk.conf file inside the sandbox, based on the content
#   of MKCONF_VARS and EXTRAMK.  Also handles some special stuff.
#
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
        echo "$var ?= $val" >> $file
    done

    if [ -n "$EXTRAMK" ]; then
        for mkfile in $EXTRAMK; do
            if [ ! -f "$mkfile" ]; then
                err "Cannot find $mkfile"
            else
                cat $mkfile >> $file
            fi
        done
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

# makeroot_libkver
#
#   If NETBSD_RELEASE is set to a version string, installs libkver
#   inside the sandbox and configures it.
#
makeroot_libkver()
{
    local prefix script statfile

    if [ "$NETBSD_RELEASE" != "no" ]; then
        _BUILD_PKG_COMP_TARGET="$BUILD_PKG_COMP_TARGET"
        BUILD_PKG_COMP_TARGET="standalone-install"
        build_and_install pkgtools/libkver
        BUILD_PKG_COMP_TARGET="$_BUILD_PKG_COMP_TARGET"
        echo "LD_PRELOAD=${LIBKVER_STANDALONE_PREFIX}/lib/libkver.so; export LD_PRELOAD" >> $DESTDIR/etc/shrc
        echo "setenv LD_PRELOAD ${LIBKVER_STANDALONE_PREFIX}/lib/libkver.so" >> $DESTDIR/etc/csh.login
        echo "setenv LD_PRELOAD ${LIBKVER_STANDALONE_PREFIX}/lib/libkver.so" >> $DESTDIR/etc/csh.cshrc
        ln -s "$NETBSD_RELEASE" $DESTDIR/libkver_osrelease
    fi
}

# makeroot_x11
#
#   If X11 is enabled, installs x11-links inside the sandbox.
#
makeroot_x11()
{
    if [ "$SETS_X11" != "no" ]; then
        [ "$Nflag" = "no" ] && build_and_install pkgtools/x11-links
    fi
}

# ----------------------------------------------------------------------
# auto target
# ----------------------------------------------------------------------

# pkg_auto pkgs
#
#   The 'auto' target.
#
pkg_auto()
{
    local pkgs rfile target

    pkgs="${*:-${AUTO_PACKAGES}}"
    rfile=${DESTDIR}/pkg_comp/tmp/auto.list
    target="${AUTO_TARGET}"

    [ -z "${REAL_PACKAGES}" ] && err "this is useless without REAL_PACKAGES"
    [ -z "${pkgs}" ] &&
        err "this is useless without AUTO_PACKAGES nor package names"

    if [ "$1" = resume ]; then
        [ -f ${rfile} ] || err "there is no auto build to resume"
        pkgs=`cat ${rfile}`
    elif [ -f ${rfile} ]; then
        err "there is an stopped auto build; removeroot first or resume it"
    else
        makeroot

        [ "$nflag" = "no" -a -n "$INSTALL_PACKAGES" ] &&
            pkg_install $INSTALL_PACKAGES

        echo ${pkgs} | tr ' ' '\n' > ${rfile}
    fi

    checkroot
    _BUILD_RESUME=${rfile} BUILD_PKG_COMP_TARGET=${target} pkg_build ${pkgs}
    pkg_removeroot
}

# generate_pkg_summary directory
#
#    Generates a pkg_summary.gz file in the specified directory.
generate_pkg_summary()
{
    local directory="${1}"; shift

    echo "PKG_COMP ==> Generating pkg_summary.tgz"
    for pkg in "${directory}"/*.tgz; do pkg_info -X "${pkg}"; done \
        | gzip -c >"${directory}"/pkg_summary.gz
}

# ----------------------------------------------------------------------
# build target
# ----------------------------------------------------------------------

# pkg_build pkgs
#
#   The build target.  Also used as a helper function within this script
#   to build several packages when needed.
#
pkg_build()
{
    local failed invalid p pkgs script statfile

    pkgs=
    invalid=
    for pkg in "${@}"; do
        local match="$(find_pkg "${pkg}")"
        if [ -z "${match}" ]; then
            invalid="${invalid} ${pkg}"
        else
            pkgs="${pkgs} ${match}"
        fi
    done
    if [ -n "$invalid" ]; then
        err "invalid packages:$invalid"
    fi

    # Build them
    fsmount
    copy_vulnerabilities
    failed=""
    for p in $pkgs; do
        echo "PKG_COMP ==> Building and installing $p"
        prefix=$(mktemp $DESTDIR/pkg_comp/tmp/pkg_comp-XXXXXX)
        rm $prefix
        script="$prefix.sh"
        statfile="$prefix.stat"
        init_script $script
        cat >> $script <<EOF
cd /usr/pkgsrc/$p
make $BUILD_PKG_COMP_TARGET
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
        elif [ -n "${_BUILD_RESUME}" ]; then
            grep -v "^${p}\$" < ${_BUILD_RESUME} > ${_BUILD_RESUME}.new
            mv ${_BUILD_RESUME}.new ${_BUILD_RESUME}
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
    if [ "${GENERATE_PKG_SUMMARY}" = yes ]; then
        generate_pkg_summary "${REAL_PACKAGES}/All"
    fi
}

# find_pkg name
#
#   Checks if the given package exists and outputs its path within pkgsrc.
#   Outputs nothing if the package is not found.
find_pkg()
{
    local name="${1}"

    case "${name}" in
    */*)
        if [ -d "${REAL_PKGSRC}/${name}" ]; then
            echo "${name}"
        else
            :  # Not found; output nothing.
        fi
        ;;
    *)
        local match="$(cd "${REAL_PKGSRC}" && echo */"${name}")"
        if [ -d "${REAL_PKGSRC}/${match}" ]; then
            echo "${match}"
        else
            :  # Not found; output nothing.
        fi
    esac
}

# build_and_install pkg
#
#   Builds a package and ensures it gets installed.  The use of destdir to
#   build packages may cause a package to get built but not installed,
#   which is not OK for this script.  This is for internal usage only.
#
build_and_install()
{
    pkg=${1}
    fsmount
    if pkg_build ${pkg}; then
        script=$(mktemp ${DESTDIR}/pkg_comp/tmp/pkg_comp-XXXXXX).sh
        init_script ${script}
        cat >>${script} <<EOF
cd /usr/pkgsrc/${pkg}
pkgname=\$(make show-var VARNAME=PKGNAME)
if pkg_info -E \${pkgname} 2>/dev/null; then
    :
else
    echo "PKG_COMP ==> Forcing installation of \${pkgname}"
    cd /pkg_comp/packages/All
    pkg_add \${pkgname}
fi
EOF
        chmod +x ${script}
        chroot ${DESTDIR} /pkg_comp/tmp/$(basename ${script})
        rm ${script}
    fi
    fsumount
}

# ----------------------------------------------------------------------
# install target
# ----------------------------------------------------------------------

# pkg_install pkgs
#
#   The install target.  Also used as a helper function within this
#   script to install several packages when needed.
#
pkg_install()
{
    local failed pkgs stat

    pkgs="$*"

    [ -z "$REAL_PACKAGES" ] && err "REAL_PACKAGES is not set"

    copy_vulnerabilities

    fsmount
    failed=""
    for p in $(cd ${REAL_PACKAGES}/All && echo ${pkgs}); do
        echo "PKG_COMP ==> Installing binary package: $p"
        stat=$DESTDIR/pkg_comp/tmp/install.sh
        init_script $stat
        cat >> $stat <<EOF
cd /pkg_comp/packages/All
pkg_add $p
EOF
        chmod +x $stat
        chroot $DESTDIR /pkg_comp/tmp/install.sh || failed="$failed $p"
        rm $stat
    done
    fsumount
    [ -n "$failed" ] && echo "Installation failed for:$failed"
}

# ----------------------------------------------------------------------
# chroot target
# ----------------------------------------------------------------------

# pkg_chroot cmd
#
#   The 'chroot' target.
#
pkg_chroot()
{
    local prefix script exitstatus

    [ -d $DESTDIR ] || err "$DESTDIR does not exist"

    copy_vulnerabilities

    fsmount
    echo "PKG_COMP ==> Entering sandbox \`$DESTDIR'"
    prefix=$(mktemp $DESTDIR/pkg_comp/tmp/pkg_comp-XXXXXX)
    rm $prefix
    script="$prefix.sh"
    init_script $script
    if [ $# -eq 0 ]; then
        cat >> $script <<EOF
ENV=/etc/shrc $ROOTSHELL
EOF
    else
        cat >> $script <<EOF
$*
EOF
    fi
    chmod +x $script
    ENV=/etc/shrc chroot $DESTDIR /pkg_comp/tmp/`basename $script`
    exitstatus=$?
    echo
    rm $script
    fsumount
    return $exitstatus
}

# ----------------------------------------------------------------------
# removeroot target
# ----------------------------------------------------------------------

# pkg_removeroot
#
#   The 'removeroot' target.
#
pkg_removeroot()
{
    [ -f $fsstate ] && err "filesystems may still be mounted; cannot remove"
    echo "PKG_COMP ==> Removing sandbox \`${DESTDIR}'"
    rm -rf $DESTDIR
}

# ----------------------------------------------------------------------
# Main program
# ----------------------------------------------------------------------

confdir="$HOME/pkg_comp"

# Parse options
args=`getopt c:C:nN $*`
if [ $? != 0 ]; then
    usage
fi
set -- $args
conffile=
nflag=no
Nflag=no
while [ $# -gt 0 ]; do
    case "$1" in
        -c)
            [ -n "$conffile" ] && usage
            conffile="$confdir/$2.conf"
            shift
            ;;
        -C)
            [ -n "$conffile" ] && usage
            conffile="$2"
            shift
            ;;
        -n)
            nflag=yes
            ;;
        -N)
            nflag=yes
            Nflag=yes
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

case "$1" in
    pkg_*)
        target=chroot
        ;;
    *)
        target="$1"
        shift
        ;;
esac
args="$*"

# readconf
#
#   Reads the configuration file and ensures that the environment is in
#   a consistent state.
#
readconf()
{
    if [ -f $conffile ]; then
        [ `id -u` -ne 0 ] && err "must be run as root"
        env_clean
        . $conffile
        env_setdefaults
    else
        err "$conffile does not exist"
    fi

    fsstate="$DESTDIR/pkg_comp/tmp/mount.stat"
}

# checkroot
#
#   Checks that the sandbox is initialized, that it's a valid directory
#   and configures a signal trap for SIGINT and SIGQUIT.
#
checkroot()
{
    if [ ! -d "$DESTDIR" ]; then
        err "sandbox not initialized; use makeroot first."
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
        exit $?
        ;;
    removeroot)
        readconf
        checkroot
        pkg_removeroot
        ;;
    auto)
        readconf
        pkg_auto $args
        ;;
    *)
        err "unknown target \`$target'"
        ;;
esac

exit 0

# vim: expandtab:softtabstop=4:shiftwidth=4
