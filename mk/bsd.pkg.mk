#	$NetBSD: bsd.pkg.mk,v 1.138 1998/08/06 14:49:41 agc Exp $
#
# This file is in the public domain.
#
# This file is derived from bsd.port.mk - 940820 Jordan K. Hubbard.
#
# Please see the NetBSD packages(7) manual page for details on the
# that variables used in this make file template.

# Default sequence for "all" is:  fetch checksum extract patch configure build
#
# Please read the comments in the targets section below, you
# should be able to use the pre-* or post-* targets/scripts
# (which are available for every stage except checksum) or
# override the do-* targets to do pretty much anything you want.
#
# NEVER override the "regular" targets unless you want to open
# a major can of worms.

# Get the operating system type
OPSYS!=	uname -s

# Include any preferences, if not already included
.include "../../mk/bsd.prefs.mk"

.if defined(ONLY_FOR_ARCHS)
.for __ARCH in ${ONLY_FOR_ARCHS}
.if ${MACHINE_ARCH:M${__ARCH}} != ""
__ARCH_OK?=	1
.endif
.endfor
.else
__ARCH_OK?=	1
.endif

.if exists(${.CURDIR}/../Makefile.inc)
.include "${.CURDIR}/../Makefile.inc"
.endif

.if (${OPSYS} == "OpenBSD")
NOMANCOMPRESS?=	yes
DEF_UMASK?=		022
.elif (${OPSYS} == "NetBSD")
DEF_UMASK?=		0022
NOCLEANDEPENDS=	yes
.else
DEF_UMASK?=		0022
.endif

.if exists(${.CURDIR}/Makefile.${MACHINE_ARCH}-${OPSYS})
.include "${.CURDIR}/Makefile.${MACHINE_ARCH}-${OPSYS}"
.elif exists(${.CURDIR}/Makefile.${OPSYS})
.include "${.CURDIR}/Makefile.${OPSYS}"
.elif exists(${.CURDIR}/Makefile.${MACHINE_ARCH})
.include "${.CURDIR}/Makefile.${MACHINE_ARCH}"
.endif

.if (${OPSYS} == "NetBSD")
LOCALBASE?=		${DESTDIR}/usr/pkg
.else
LOCALBASE?=		${DESTDIR}/usr/local
.endif
X11BASE?=		${DESTDIR}/usr/X11R6

PKGSRCDIR=		${.CURDIR}/../..
DISTDIR?=		${PKGSRCDIR}/distfiles
_DISTDIR?=		${DISTDIR}/${DIST_SUBDIR}
PACKAGES?=		${PKGSRCDIR}/packages
TEMPLATES?=		${PKGSRCDIR}/templates

.if exists(${.CURDIR}/patches.${MACHINE_ARCH}-${OPSYS})
PATCHDIR?=		${.CURDIR}/patches.${MACHINE_ARCH}-${OPSYS}
.elif exists(${.CURDIR}/patches.${OPSYS})
PATCHDIR?=		${.CURDIR}/patches.${OPSYS}
.elif exists(${.CURDIR}/patches.${MACHINE_ARCH})
PATCHDIR?=		${.CURDIR}/patches.${MACHINE_ARCH}
.else
PATCHDIR?=		${.CURDIR}/patches
.endif

.if exists(${.CURDIR}/scripts.${MACHINE_ARCH}-${OPSYS})
SCRIPTDIR?=		${.CURDIR}/scripts.${MACHINE_ARCH}-${OPSYS}
.elif exists(${.CURDIR}/scripts.${OPSYS})
SCRIPTDIR?=		${.CURDIR}/scripts.${OPSYS}
.elif exists(${.CURDIR}/scripts.${MACHINE_ARCH})
SCRIPTDIR?=		${.CURDIR}/scripts.${MACHINE_ARCH}
.else
SCRIPTDIR?=		${.CURDIR}/scripts
.endif

.if exists(${.CURDIR}/files.${MACHINE_ARCH}-${OPSYS})
FILESDIR?=		${.CURDIR}/files.${MACHINE_ARCH}-${OPSYS}
.elif exists(${.CURDIR}/files.${OPSYS})
FILESDIR?=		${.CURDIR}/files.${OPSYS}
.elif exists(${.CURDIR}/files.${MACHINE_ARCH})
FILESDIR?=		${.CURDIR}/files.${MACHINE_ARCH}
.else
FILESDIR?=		${.CURDIR}/files
.endif

.if exists(${.CURDIR}/pkg.${MACHINE_ARCH}-${OPSYS})
PKGDIR?=		${.CURDIR}/pkg.${MACHINE_ARCH}-${OPSYS}
.elif exists(${.CURDIR}/pkg.${OPSYS})
PKGDIR?=		${.CURDIR}/pkg.${OPSYS}
.elif exists(${.CURDIR}/pkg.${MACHINE_ARCH})
PKGDIR?=		${.CURDIR}/pkg.${MACHINE_ARCH}
.else
PKGDIR?=		${.CURDIR}/pkg
.endif

.if defined(USE_IMAKE) || defined(USE_MOTIF) || defined(USE_X11)
.if defined(USE_LOCALBASE_FOR_X11)
PREFIX?=		${LOCALBASE}
BUILD_DEPENDS+=		${X11BASE}/lib/X11/config/xpkgwedge.def:../../x11/xpkgwedge
.else
PREFIX?=		${X11BASE}
.endif
.else
PREFIX?=		${LOCALBASE}
.endif

.if defined(USE_GMAKE)
BUILD_DEPENDS+=		${GMAKE}:${PKGSRCDIR}/devel/gmake
MAKE_PROGRAM=		${GMAKE}
.else
MAKE_PROGRAM=		${MAKE}
.endif
.if defined(USE_PERL5)
DEPENDS+=		perl-5.00404:${PKGSRCDIR}/lang/perl5
.endif
.if defined(INFO_FILES)
USE_GTEXINFO=		yes
.endif
.if defined(USE_GTEXINFO)
DEPENDS+=		gtexinfo-3.12:${PKGSRCDIR}/devel/gtexinfo
.endif
.if defined(USE_MOTIF)
.if exists(${X11BASE}/include/Xm/Xm.h)
RUN_DEPENDS+=		${X11BASE}/include/Xm/Xm.h:../../x11/lesstif
.else
RUN_DEPENDS+=		${PREFIX}/include/Xm/Xm.h:../../x11/lesstif
BUILD_DEPENDS+=		${PREFIX}/include/Xm/Xm.h:../../x11/lesstif
.endif
.endif
.if defined(USE_LIBTOOL)
LIBTOOL=		${LOCALBASE}/bin/libtool
BUILD_DEPENDS+=		${LIBTOOL}:../../devel/libtool
CONFIGURE_ENV+=		LIBTOOL=${LIBTOOL}
MAKE_ENV+=		LIBTOOL=${LIBTOOL}
.endif

.if exists(${PKGSRCDIR}/../Makefile.inc)
.include "${PKGSRCDIR}/../Makefile.inc"
.endif

# Don't change these!!!  These names are built into the _TARGET_USE macro,
# there is no way to refer to them cleanly from within the macro AFAIK.
EXTRACT_COOKIE?=	${WRKDIR}/.extract_done
CONFIGURE_COOKIE?=	${WRKDIR}/.configure_done
INSTALL_COOKIE?=	${WRKDIR}/.install_done
BUILD_COOKIE?=		${WRKDIR}/.build_done
PATCH_COOKIE?=		${WRKDIR}/.patch_done
PACKAGE_COOKIE?=	${WRKDIR}/.package_done

# Miscellaneous overridable commands:
GMAKE?=			gmake
XMKMF?=			xmkmf -a
.if exists(/sbin/md5)
MD5?=			/sbin/md5
.elif exists(/bin/md5)
MD5?=			/bin/md5
.elif exists(/usr/bin/md5)
MD5?=			/usr/bin/md5
.else
MD5?=			md5
.endif
MD5_FILE?=		${FILESDIR}/md5

MAKE_FLAGS?=
MAKEFILE?=		Makefile
MAKE_ENV+=		PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE} MOTIFLIB="${MOTIFLIB}" CFLAGS="${CFLAGS}"

.if exists(/usr/bin/fetch)
FETCH_CMD?=		/usr/bin/fetch
.else
FETCH_CMD?=		/usr/bin/ftp
.endif

# By default, distfiles have no restrictions placed on them
MIRROR_DISTFILE?=	yes

TOUCH?=			/usr/bin/touch
TOUCH_FLAGS?=	-f

PATCH?=			/usr/bin/patch
PATCH_STRIP?=	-p0
PATCH_DIST_STRIP?=	-p0
.if defined(PATCH_DEBUG) || defined(PKG_VERBOSE)
PATCH_DEBUG_TMP=	yes
PATCH_ARGS?=	-d ${WRKSRC} -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${WRKSRC} -E ${PATCH_DIST_STRIP}
.else
PATCH_DEBUG_TMP=	no
PATCH_ARGS?=	-d ${WRKSRC} --forward --quiet -E ${PATCH_STRIP}
PATCH_DIST_ARGS?=	-d ${WRKSRC} --forward --quiet -E ${PATCH_DIST_STRIP}
.endif
.if defined(BATCH)
PATCH_ARGS+=		--batch
PATCH_DIST_ARGS+=	--batch
.endif

.if defined(PATCH_CHECK_ONLY)
PATCH_ARGS+=	-C
PATCH_DIST_ARGS+=	-C
.endif

# Turn off pax on NetBSD for just now.  pax is not bug-compatible with
# GNU tar yet, and some of the archives contain dross after the end of
# archive.  tar ignores this, pax thinks it's valid, and asks for the
# second volume of the archive.

.if exists(/bin/pax) && (${OPSYS} != "NetBSD")
EXTRACT_CMD?=		/bin/pax
EXTRACT_BEFORE_ARGS?=	-zrf
.else
.if exists(/bin/tar)
EXTRACT_CMD?=		/bin/tar
.else
EXTRACT_CMD?=		/usr/bin/tar
.endif
# Backwards compatability.
.if defined(EXTRACT_ARGS)
EXTRACT_BEFORE_ARGS?=   ${EXTRACT_ARGS}
.else
EXTRACT_BEFORE_ARGS?=   -xzf
.endif
.endif
EXTRACT_SUFX?=		.tar.gz

# Figure out where the local mtree file is
.if !defined(MTREE_FILE)
.if defined(USE_IMAKE) || defined(USE_MOTIF) || defined(USE_X11)
MTREE_FILE=	/etc/mtree/BSD.x11.dist
.else
.if (${OPSYS} == "NetBSD")
MTREE_FILE=	/etc/mtree/BSD.pkg.dist
.else
MTREE_FILE=	/etc/mtree/BSD.local.dist
.endif
.endif
.endif
MTREE_CMD?=	/usr/sbin/mtree
MTREE_ARGS?=	-U -f ${MTREE_FILE} -d -e -p

.if (${OPSYS} == "OpenBSD")
.include <bsd.own.mk>
MAKE_ENV+=	EXTRA_SYS_MK_INCLUDES="<bsd.own.mk>"
.elif (${OPSYS} == "NetBSD")
NEED_OWN_INSTALL_TARGET=	no
.include "../../mk/bsd.own.mk"
SHAREOWN = ${DOCOWN}
SHAREGRP = ${DOCGRP}
SHAREMODE = ${DOCMODE}
.endif

.if !defined(NO_WRKDIR)
.if defined(OBJMACHINE)
WRKDIR_BASENAME?=	work.${MACHINE_ARCH}
.else # OBJMACHINE
WRKDIR_BASENAME?=	work
.endif # OBJMACHINE
WRKDIR?=		${.CURDIR}/${WRKDIR_BASENAME}
.else # !NO_WRKDIR
WRKDIR?=		${.CURDIR}
.endif # !NO_WRKDIR
.if defined(NO_WRKSUBDIR)
WRKSRC?=		${WRKDIR}
.else # NO_WRKSUBDIR
WRKSRC?=		${WRKDIR}/${DISTNAME}
.endif # NO_WRKSUBDIR

.if defined(WRKOBJDIR)
# XXX Is pwd -P available in FreeBSD's /bin/sh?
__canonical_PKGSRCDIR!=	cd ${PKGSRCDIR}; pwd -P
__canonical_CURDIR!=	cd ${.CURDIR}; pwd -P
PORTSUBDIR=		${__canonical_CURDIR:S,${__canonical_PKGSRCDIR}/,,}
.endif

# A few aliases for *-install targets
INSTALL_PROGRAM= \
	${INSTALL} ${COPY} ${STRIPFLAG} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT= \
	${INSTALL} ${COPY} -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_DATA= \
	${INSTALL} ${COPY} -o ${SHAREOWN} -g ${SHAREGRP} -m ${SHAREMODE}
INSTALL_MAN= \
	${INSTALL} ${COPY} -o ${MANOWN} -g ${MANGRP} -m ${MANMODE}
INSTALL_PROGRAM_DIR= \
	${INSTALL} -d -o ${BINOWN} -g ${BINGRP} -m ${BINMODE}
INSTALL_SCRIPT_DIR= \
	${INSTALL_PROGRAM_DIR}
INSTALL_DATA_DIR= \
	${INSTALL} -d -o ${SHAREOWN} -g ${SHAREGRP} -m ${BINMODE}
INSTALL_MAN_DIR= \
	${INSTALL} -d -o ${MANOWN} -g ${MANGRP} -m ${BINMODE}

INSTALL_MACROS=	BSD_INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			BSD_INSTALL_SCRIPT="${INSTALL_SCRIPT}" \
			BSD_INSTALL_DATA="${INSTALL_DATA}" \
			BSD_INSTALL_MAN="${INSTALL_MAN}" \
			BSD_INSTALL_PROGRAM_DIR="${INSTALL_PROGRAM_DIR}" \
			BSD_INSTALL_SCRIPT_DIR="${INSTALL_SCRIPT_DIR}" \
			BSD_INSTALL_DATA_DIR="${INSTALL_DATA_DIR}" \
			BSD_INSTALL_MAN_DIR="${INSTALL_MAN_DIR}"
MAKE_ENV+=	${INSTALL_MACROS}
SCRIPTS_ENV+=	${INSTALL_MACROS}

# The user can override the NO_PACKAGE by specifying this from
# the make command line
.if defined(FORCE_PACKAGE)
.undef NO_PACKAGE
.endif

COMMENT?=	${PKGDIR}/COMMENT
DESCR?=		${PKGDIR}/DESCR
PLIST=		${WRKDIR}/.PLIST

PKG_CMD?=		/usr/sbin/pkg_create
.if !defined(PKG_ARGS)
PKG_ARGS=		-v -c ${COMMENT} -d ${DESCR} -f ${PLIST} -p ${PREFIX} -P "`${MAKE} package-depends|sort -u`"
.if defined(CONFLICTS)
# Only use -C if the pkg_create command supports it.
__PKG_CMD_C__!= ${PKG_CMD} -C 2>&1 | /usr/bin/egrep 'illegal option' ; echo
.if (${__PKG_CMD_C__} == "")
PKG_ARGS+=		-C "${CONFLICTS}"
.endif
.endif
.if exists(${PKGDIR}/INSTALL)
PKG_ARGS+=		-i ${PKGDIR}/INSTALL
.endif
.if exists(${PKGDIR}/DEINSTALL)
PKG_ARGS+=		-k ${PKGDIR}/DEINSTALL
.endif
.if exists(${PKGDIR}/REQ)
PKG_ARGS+=		-r ${PKGDIR}/REQ
.endif
.if exists(${PKGDIR}/MESSAGE)
PKG_ARGS+=		-D ${PKGDIR}/MESSAGE
.endif
.if !defined(NO_MTREE)
PKG_ARGS+=		-m ${MTREE_FILE}
.endif
.endif
PKG_SUFX?=		.tgz
# where pkg_add records its dirty deeds.
PKG_DBDIR?=		/var/db/pkg

# shared/dynamic motif libs
MOTIFLIB?=	-L${X11BASE}/lib -L${LOCALBASE}/lib -Wl,-R${X11BASE}/lib -Wl,-R${LOCALBASE}/lib -lXm

AWK?=		/usr/bin/awk
BASENAME?=	/usr/bin/basename
CAT?=		/bin/cat
CP?=		/bin/cp
ECHO?=		/bin/echo
FALSE?=		/usr/bin/false
FILE?=		/usr/bin/file
GREP?=		/usr/bin/grep
GUNZIP_CMD?=	/usr/bin/gunzip -f
GZCAT?=		/usr/bin/gzcat
GZIP?=		-9
GZIP_CMD?=	/usr/bin/gzip -nf ${GZIP}
LDCONFIG?=	/sbin/ldconfig
LN?=		/bin/ln
MKDIR?=		/bin/mkdir -p
MV?=		/bin/mv
RM?=		/bin/rm
RMDIR?=		/bin/rmdir
SED?=		/usr/bin/sed
SETENV?=	/usr/bin/env
SH?=		/bin/sh
TR?=		/usr/bin/tr
TRUE?=		/usr/bin/true

# Used to print all the '===>' style prompts - override this to turn them off.
ECHO_MSG?=		${ECHO}

# How to do nothing.  Override if you, for some strange reason, would rather
# do something.
DO_NADA?=		${TRUE}

ALL_TARGET?=		all
INSTALL_TARGET?=	install

.if defined(USE_IMAKE) && !defined(NO_INSTALL_MANPAGES)
INSTALL_TARGET+=	install.man
.endif

# If this host is behind a filtering firewall, use passive ftp(1)
.if defined(PASSIVE_FETCH)
FETCH_BEFORE_ARGS += -p
.endif

# Popular master sites
MASTER_SITE_XCONTRIB+=	\
	ftp://crl.dec.com/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.eu.net/X11/contrib/%SUBDIR%/ \
	ftp://ftp.uni-paderborn.de/pub/X11/contrib/%SUBDIR%/ \
	ftp://ftp.x.org/contrib/%SUBDIR%/

MASTER_SITE_GNU+=	\
	ftp://prep.ai.mit.edu/pub/gnu/%SUBDIR%/ \
	ftp://wuarchive.wustl.edu/systems/gnu/%SUBDIR%/

MASTER_SITE_PERL_CPAN+=	\
	ftp://ftp.digital.com/pub/plan/perl/CPAN/modules/by-module/%SUBDIR%/ \
	ftp://ftp.cdrom.com/pub/perl/CPAN/modules/by-module/%SUBDIR%/

MASTER_SITE_TEX_CTAN+=  \
	ftp://ftp.cdrom.com/pub/tex/ctan/%SUBDIR%/  \
	ftp://wuarchive.wustl.edu/packages/TeX/%SUBDIR%/  \
	ftp://ftp.funet.fi/pub/TeX/CTAN/%SUBDIR%/  \
	ftp://ftp.tex.ac.uk/public/ctan/tex-archive/%SUBDIR%/  \
	ftp://ftp.dante.de/tex-archive/%SUBDIR%/

MASTER_SITE_SUNSITE+=	\
	ftp://sunsite.unc.edu/pub/Linux/%SUBDIR%/ \
	ftp://ftp.infomagic.com/pub/mirrors/linux/sunsite/%SUBDIR%/ \
	ftp://ftp.funet.fi/pub/mirrors/sunsite.unc.edu/pub/Linux/%SUBDIR%/

# Empty declaration to avoid "variable MASTER_SITES recursive" error
MASTER_SITES?=
PATCH_SITES?=

# Substitute subdirectory names
MASTER_SITES:=	${MASTER_SITES:S/%SUBDIR%/${MASTER_SITE_SUBDIR}/}
PATCH_SITES:=	${PATCH_SITES:S/%SUBDIR%/${PATCH_SITE_SUBDIR}/}

# The primary backup site.
MASTER_SITE_BACKUP?=	\
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/${DIST_SUBDIR}/ \
	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/${DIST_SUBDIR}/

# If the user has this set, go to the FreeBSD repository for everything.
.if defined(MASTER_SITE_FREEBSD)
MASTER_SITE_OVERRIDE=  ${MASTER_SITE_BACKUP}
.endif

# Where to put distfiles that don't have any other master site
MASTER_SITE_LOCAL?= \
	ftp://ftp.netbsd.org/pub/NetBSD/packages/distfiles/LOCAL_PORTS/ \
	ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/LOCAL_PORTS/

# I guess we're in the master distribution business! :)  As we gain mirror
# sites for distfiles, add them to this list.
.if !defined(MASTER_SITE_OVERRIDE)
MASTER_SITES+=	${MASTER_SITE_BACKUP}
PATCH_SITES+=	${MASTER_SITE_BACKUP}
.else
MASTER_SITES:=	${MASTER_SITE_OVERRIDE} ${MASTER_SITES}
PATCH_SITES:=	${MASTER_SITE_OVERRIDE} ${PATCH_SITES}
.endif

# Derived names so that they're easily overridable.
DISTFILES?=		${DISTNAME}${EXTRACT_SUFX}
PKGNAME?=		${DISTNAME}

MAINTAINER?=		packages@netbsd.org

ALLFILES?=	${DISTFILES} ${PATCHFILES}

.if defined(IGNOREFILES)
CKSUMFILES!=	\
	for file in ${ALLFILES}; do \
		ignore=0; \
		for tmp in ${IGNOREFILES}; do \
			if [ "$$file" = "$$tmp" ]; then \
				ignore=1; \
			fi; \
		done; \
		if [ "$$ignore" = 0 ]; then \
			echo "$$file"; \
		else \
			echo ""; \
		fi; \
	done
.else
CKSUMFILES=		${ALLFILES}
.endif

# List of all files, with ${DIST_SUBDIR} in front.  Used for checksum.
.if defined(DIST_SUBDIR)
_CKSUMFILES?=	${CKSUMFILES:S/^/${DIST_SUBDIR}\//}
_IGNOREFILES?=	${IGNOREFILES:S/^/${DIST_SUBDIR}\//}
.else
_CKSUMFILES?=	${CKSUMFILES}
_IGNOREFILES?=	${IGNOREFILES}
.endif

# This is what is actually going to be extracted, and is overridable
#  by user.
EXTRACT_ONLY?=	${DISTFILES}

.if !defined(CATEGORIES) || !defined(DISTNAME)
.BEGIN:
	@${ECHO_MSG} "CATEGORIES and DISTNAME are mandatory."
	@${FALSE}
.endif

.if defined(LIB_DEPENDS)
.BEGIN:
	@${ECHO_MSG} "LIB_DEPENDS is deprecated, and must be replaced with DEPENDS."
	@${FALSE}
.endif

# Note this has to start with a capital letter (or more accurately, it
#  shouldn't match "[a-z]*"), see the target "delete-package-links" below.
PKGREPOSITORYSUBDIR?=	All
PKGREPOSITORY?=		${PACKAGES}/${PKGREPOSITORYSUBDIR}
.if exists(${PACKAGES})
PKGFILE?=		${PKGREPOSITORY}/${PKGNAME}${PKG_SUFX}
.else
PKGFILE?=		${PKGNAME}${PKG_SUFX}
.endif

CONFIGURE_SCRIPT?=	configure
CONFIGURE_ENV+=		PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--host=${MACHINE_GNU_ARCH}--netbsd --prefix=${PREFIX}
HAS_CONFIGURE=		yes
.endif

# Passed to most of script invocations
SCRIPTS_ENV+= CURDIR=${.CURDIR} DISTDIR=${DISTDIR} \
	PATH=${PATH}:${LOCALBASE}/bin:${X11BASE}/bin \
	WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} PATCHDIR=${PATCHDIR} \
	SCRIPTDIR=${SCRIPTDIR} FILESDIR=${FILESDIR} \
	PKGSRCDIR=${PKGSRCDIR} DEPENDS="${DEPENDS}" \
	PREFIX=${PREFIX} LOCALBASE=${LOCALBASE} X11BASE=${X11BASE}

.if defined(BATCH)
SCRIPTS_ENV+=	BATCH=yes
.endif

.MAIN: all

# Use aliases, so that all versions of English are acceptable
.if defined(LICENCE) && !defined(LICENSE)
LICENSE=	${LICENCE}
.endif

.if defined(ACCEPTABLE_LICENCES) && !defined(ACCEPTABLE_LICENSES)
ACCEPTABLE_LICENSES=	${ACCEPTABLE_LICENCES}
.endif

################################################################
# Many ways to disable a port.
#
# If we're in BATCH mode and the port is interactive, or we're
# in interactive mode and the port is non-interactive, skip all
# the important targets.  The reason we have two modes is that
# one might want to leave a build in BATCH mode running
# overnight, then come back in the morning and do _only_ the
# interactive ones that required your intervention.
#
# Don't attempt to build ports that require Motif if you don't
# have Motif.
#
# Ignore ports that can't be resold if building for a CDROM.
#
# Don't build a port if it's restricted and we don't want to get
# into that.
#
# Don't build a port if it's broken.
################################################################

.if !defined(NO_IGNORE)
.if (defined(IS_INTERACTIVE) && defined(BATCH))
IGNORE=	"is an interactive port"
.elif (!defined(IS_INTERACTIVE) && defined(INTERACTIVE))
IGNORE=	"is not an interactive port"
.elif (defined(NO_CDROM) && defined(FOR_CDROM))
IGNORE=	"may not be placed on a CDROM: ${NO_CDROM}"
.elif (defined(RESTRICTED) && defined(NO_RESTRICTED))
IGNORE=	"is restricted: ${RESTRICTED}"
.elif ((defined(USE_IMAKE) || defined(USE_MOTIF) || defined(USE_X11)) && \
       !exists(${X11BASE}))
IGNORE=	"uses X11, but ${X11BASE} not found"
.elif defined(BROKEN)
IGNORE=	"is marked as broken: ${BROKEN}"
.elif defined(LICENSE)
.ifdef ACCEPTABLE_LICENSES
.for _lic in ${ACCEPTABLE_LICENSES}
.if ${LICENSE} == "${_lic}"
_ACCEPTABLE=	yes
.endif
.endfor	# _lic
.endif	# ACCEPTABLE_LICENSES
.ifndef _ACCEPTABLE
IGNORE=	"Unacceptable license: ${LICENSE}"
.endif
.endif

.if defined(IGNORE)
.if defined(IGNORE_SILENT)
IGNORECMD=	${DO_NADA}
.else
IGNORECMD=	${ECHO_MSG} "===>  ${PKGNAME} ${IGNORE}."
.endif
fetch:
	@${IGNORECMD}
checksum:
	@${IGNORECMD}
extract:
	@${IGNORECMD}
patch:
	@${IGNORECMD}
configure:
	@${IGNORECMD}
all:
	@${IGNORECMD}
build:
	@${IGNORECMD}
install:
	@${IGNORECMD}
deinstall:
	@${IGNORECMD}
package:
	@${IGNORECMD}
.endif # IGNORE
.endif # !NO_IGNORE

.if !defined(__ARCH_OK)
.MAIN:	all

fetch fetch-list extract patch configure build install reinstall package checkpatch checksum makesum all:
	@echo "This port is only for ${ONLY_FOR_ARCHS},"
	@echo "and you are running ${MACHINE_ARCH}."
.else

.if defined(ALL_HOOK)
all:
	@cd ${.CURDIR} && ${SETENV} CURDIR=${.CURDIR} DISTNAME=${DISTNAME} \
	  DISTDIR=${DISTDIR} WRKDIR=${WRKDIR} WRKSRC=${WRKSRC} \
	  PATCHDIR=${PATCHDIR} SCRIPTDIR=${SCRIPTDIR} \
	  FILESDIR=${FILESDIR} PKGSRCDIR=${PKGSRCDIR} PREFIX=${PREFIX} \
	  DEPENDS="${DEPENDS}" BUILD_DEPENDS="${BUILD_DEPENDS}" \
	  RUN_DEPENDS="${RUN_DEPENDS}" CONFLICTS="${CONFLICTS}" X11BASE=${X11BASE} \
	${ALL_HOOK}
.endif

.if !target(all)
all: build
.endif

.if !defined(DEPENDS_TARGET)
.if make(reinstall)
DEPENDS_TARGET=	reinstall
.else
DEPENDS_TARGET=	install
.endif
.endif

################################################################
# The following are used to create easy dummy targets for
# disabling some bit of default target behavior you don't want.
# They still check to see if the target exists, and if so don't
# do anything, since you might want to set this globally for a
# group of ports in a Makefile.inc, but still be able to
# override from an individual Makefile.
################################################################

# Disable checksum
.if (defined(NO_CHECKSUM) && !target(checksum)) || exists(${EXTRACT_COOKIE})
checksum: fetch
	@${DO_NADA}
.endif

# Disable extract
.if defined(NO_EXTRACT) && !target(extract)
extract: checksum
	@${TOUCH} ${TOUCH_FLAGS} ${EXTRACT_COOKIE}
checksum: fetch
	@${DO_NADA}
makesum:
	@${DO_NADA}
.endif

# Disable patch
.if defined(NO_PATCH) && !target(patch)
patch: extract
	@${TOUCH} ${TOUCH_FLAGS} ${PATCH_COOKIE}
.endif

# Disable configure
.if defined(NO_CONFIGURE) && !target(configure)
configure: patch
	@${TOUCH} ${TOUCH_FLAGS} ${CONFIGURE_COOKIE}
.endif

# Disable build
.if defined(NO_BUILD) && !target(build)
build: configure
	@${TOUCH} ${TOUCH_FLAGS} ${BUILD_COOKIE}
.endif

# Disable install
.if defined(NO_INSTALL) && !target(install)
install: build
	@${TOUCH} ${TOUCH_FLAGS} ${INSTALL_COOKIE}
.endif

# Disable package
.if defined(NO_PACKAGE) && !target(package)
package:
.if defined(IGNORE_SILENT)
	@${DO_NADA}
.else
	@${ECHO_MSG} "===>  ${PKGNAME} may not be packaged: ${NO_PACKAGE}."
.endif
.endif

# Disable describe
.if defined(NO_DESCRIBE) && !target(describe)
describe:
	@${DO_NADA}
.endif

################################################################
# More standard targets start here.
#
# These are the body of the build/install framework.  If you are
# not happy with the default actions, and you can't solve it by
# adding pre-* or post-* targets/scripts, override these.
################################################################

# Fetch

.if !target(do-fetch)
do-fetch:
	@${MKDIR} ${_DISTDIR}
	@(cd ${_DISTDIR}; \
	 for file in ${DISTFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
			for site in ${MASTER_SITES}; do \
				${ECHO_MSG} ">> Attempting to fetch $$file from $${site}."; \
				if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} ${FETCH_AFTER_ARGS}; then \
					if [ -f ${MD5_FILE} ]; then \
						CKSUM=`${MD5} < ${DISTDIR}/$$file`; \
						CKSUM2=`${AWK} '$$1 == "MD5" && $$2 == "\('$$file'\)"{print $$4;}' ${MD5_FILE}`; \
						if [ "$$CKSUM" = "$$CKSUM2" -o "$$CKSUM2" = "IGNORE" ]; then \
							continue 2; \
						else \
							${ECHO_MSG} ">> Checksum failure - trying next site."; \
						fi; \
					else \
						continue 2; \
					fi; \
				fi \
			done; \
			${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} ">> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
		fi \
	 done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	 for file in ${PATCHFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			if [ -h $$file -o -h `${BASENAME} $$file` ]; then \
				${ECHO_MSG} ">> ${_DISTDIR}/$$file is a broken symlink."; \
				${ECHO_MSG} ">> Perhaps a filesystem (most likely a CD) isn't mounted?"; \
				${ECHO_MSG} ">> Please correct this problem and try again."; \
				exit 1; \
			fi ; \
			${ECHO_MSG} ">> $$file doesn't seem to exist on this system."; \
			for site in ${PATCH_SITES}; do \
			    ${ECHO_MSG} ">> Attempting to fetch from $${site}."; \
				if ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} ${FETCH_AFTER_ARGS}; then \
					continue 2; \
				fi \
			done; \
			${ECHO_MSG} ">> Couldn't fetch it - please try to retrieve this";\
			${ECHO_MSG} ">> port manually into ${_DISTDIR} and try again."; \
			exit 1; \
		fi \
	 done)
.endif
.endif

# This is for the use of sites which store distfiles which others may
# fetch - only fetch the distfile if it is allowed to be
# re-distributed freely
mirror-distfiles:
.if (${MIRROR_DISTFILE} == "yes")
	@${MAKE} fetch __ARCH_OK=yes NO_IGNORE=yes
.endif

# Extract

.if !target(do-extract)
do-extract:
.if !defined(NO_WRKDIR)
.if defined(WRKOBJDIR)
	@${RM} -rf ${WRKOBJDIR}/${PORTSUBDIR}/${WRKDIR_BASENAME}
	@${MKDIR} -p ${WRKOBJDIR}/${PORTSUBDIR}/${WRKDIR_BASENAME}
	@echo "${WRKDIR} -> ${WRKOBJDIR}/${PORTSUBDIR}/${WRKDIR_BASENAME}"
	@# XXX whatif a build is going on right now?  Is this wise?
	@${LN} -sf ${WRKOBJDIR}/${PORTSUBDIR}/${WRKDIR_BASENAME} ${WRKDIR}
.else
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
.endif
.endif
	@for file in ${EXTRACT_ONLY}; do \
		if ! (cd ${WRKDIR} && ${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${_DISTDIR}/$$file ${EXTRACT_AFTER_ARGS});\
		then \
			exit 1; \
		fi \
	done
.endif

# Patch

.if !target(do-patch)
do-patch:
.if defined(PATCHFILES)
	@${ECHO_MSG} "===>  Applying distribution patches for ${PKGNAME}"
	@(cd ${_DISTDIR}; \
	  for i in ${PATCHFILES}; do \
		if [ ${PATCH_DEBUG_TMP} = yes ]; then \
			${ECHO_MSG} "===>   Applying distribution patch $$i" ; \
		fi; \
		case $$i in \
			*.Z|*.gz) \
				${GZCAT} $$i | ${PATCH} ${PATCH_DIST_ARGS}; \
				;; \
			*) \
				${PATCH} ${PATCH_DIST_ARGS} < $$i; \
				;; \
		esac; \
	  done)
.endif
	@if [ -d ${PATCHDIR} ]; then \
		if [ "`echo ${PATCHDIR}/patch-*`" = "${PATCHDIR}/patch-*" ]; then \
			${ECHO_MSG} "===>   Ignoring empty patch directory"; \
			if [ -d ${PATCHDIR}/CVS ]; then \
				${ECHO_MSG} "===>   Perhaps you forgot the -P flag to cvs co or update?"; \
			fi; \
		else \
			${ECHO_MSG} "===>  Applying ${OPSYS} patches for ${PKGNAME}" ; \
			for i in ${PATCHDIR}/patch-*; do \
				case $$i in \
					*.orig|*.rej|*~) \
						${ECHO_MSG} "===>   Ignoring patchfile $$i" ; \
						;; \
					*) \
						if [ ${PATCH_DEBUG_TMP} = yes ]; then \
							${ECHO_MSG} "===>   Applying ${OPSYS} patch $$i" ; \
						fi; \
						${PATCH} ${PATCH_ARGS} < $$i; \
						;; \
				esac; \
			done; \
		fi; \
	fi
.endif

# Configure

.if !target(do-configure)
do-configure:
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
		  ${SCRIPTDIR}/configure; \
	fi
.if defined(HAS_CONFIGURE)
	@(cd ${WRKSRC} && CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="/usr/bin/install -c -o ${BINOWN} -g ${BINGRP}" \
	    INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	    ${CONFIGURE_ENV} ./${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})
.endif
.if defined(USE_IMAKE)
	@(cd ${WRKSRC} && ${SETENV} ${SCRIPTS_ENV} XPROJECTROOT=${X11BASE} ${XMKMF})
.endif
.endif

# Build

.if !target(do-build)
do-build:
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${ALL_TARGET})
.endif

# Install

.if !target(do-install)
do-install:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})
	@for f in ${INFO_FILES}; do		\
		${ECHO} "${LOCALBASE}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/$$f";	\
		${LOCALBASE}/bin/install-info --info-dir=${PREFIX}/info ${PREFIX}/info/$$f;		\
	done
.endif

# Package

.if !target(do-package)
do-package: ${PLIST}
	@if [ -e ${PLIST} ]; then \
		${ECHO_MSG} "===>  Building package for ${PKGNAME}"; \
		if [ -d ${PACKAGES} ]; then \
			if [ ! -d ${PKGREPOSITORY} ]; then \
				if ! ${MKDIR} ${PKGREPOSITORY}; then \
					${ECHO_MSG} ">> Can't create directory ${PKGREPOSITORY}."; \
					exit 1; \
				fi; \
			fi; \
		fi; \
		if ${PKG_CMD} ${PKG_ARGS} ${PKGFILE}; then \
			if [ -d ${PACKAGES} ]; then \
				${MAKE} ${.MAKEFLAGS} package-links; \
			fi; \
		else \
			${MAKE} ${.MAKEFLAGS} delete-package; \
			exit 1; \
		fi; \
	fi
.endif

# Some support rules for do-package

.if !target(package-links)
package-links:
	@${MAKE} ${.MAKEFLAGS} delete-package-links
	@for cat in ${CATEGORIES}; do \
		if [ ! -d ${PACKAGES}/$$cat ]; then \
			if ! ${MKDIR} ${PACKAGES}/$$cat; then \
				${ECHO_MSG} ">> Can't create directory ${PACKAGES}/$$cat."; \
				exit 1; \
			fi; \
		fi; \
		ln -s ../${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ${PACKAGES}/$$cat; \
	done;
.endif

.if !target(delete-package-links)
delete-package-links:
	@${RM} -f ${PACKAGES}/[a-z]*/${PKGNAME}${PKG_SUFX};
.endif

.if !target(delete-package)
delete-package:
	@${MAKE} ${.MAKEFLAGS} delete-package-links
	@${RM} -f ${PKGFILE}
.endif

# Set the PLIST_SRC definition, if necessary
.if !defined(PLIST_SRC)
.if exists(${PKGDIR}/PLIST)
PLIST_SRC=	${PKGDIR}/PLIST
.elif exists(${PKGDIR}/PLIST-mi) && \
      exists(${PKGDIR}/PLIST-md.shared) && \
      exists(${PKGDIR}/PLIST-md.static)
PLIST_SRC=	${PKGDIR}/PLIST-mi
.if ${MACHINE_ARCH} == "powerpc" ||  ${MACHINE_ARCH} == "mips" ||  ${MACHINE_ARCH} == "alpha"
# XXX this is mostly for perl; alpha can be removed once perl knows
#  how to do dynamic loading - hubertf
PLIST_SRC+=	${PKGDIR}/PLIST-md.static
.else
PLIST_SRC+=	${PKGDIR}/PLIST-md.shared
.endif  # powerpc || mips || alpha
.else   # no PLIST at all
PLIST_SRC=
.endif  # ${PKGDIR}/PLIST
.endif  # !PLIST_SRC

################################################################
# This is the "generic" port target, actually a macro used from the
# six main targets.  See below for more.
################################################################

_PORT_USE: .USE
.if make(real-fetch)
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} fetch-depends
.endif
.if make(real-extract)
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} build-depends misc-depends
.endif
.if make(real-install)
.if !defined(NO_PKG_REGISTER) && !defined(FORCE_PKG_REGISTER)
.if defined(CONFLICTS)
	@(/bin/sh -f -c 'for i in ${CONFLICTS}; do \
		if /usr/sbin/pkg_info -e "$$i" >${WRKDIR}/.CONFLICT.$$$$; then \
			${ECHO_MSG} "===>  ${PKGNAME} conflicts with installed package: $$i - "`${CAT} ${WRKDIR}/.CONFLICT.$$$$`" found."; \
			${ECHO_MSG} "      They install the same files into the same place."; \
			${ECHO_MSG} "      Please remove "`${CAT} ${WRKDIR}/.CONFLICT.$$$$`" first with pkg_delete(1)."; \
			exit 1; \
		fi; \
		${RM} ${WRKDIR}/.CONFLICT.$$$$ ; \
	done')
.endif
	@if [ -d ${PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO_MSG} "===>  ${PKGNAME} is already installed - perhaps an older version?"; \
		${ECHO_MSG} "      If so, you may wish to \`\`${MAKE} deinstall'' and install"; \
		${ECHO_MSG} "      this port again by \`\`${MAKE} reinstall'' to upgrade it properly."; \
		${ECHO_MSG} "      If you really wish to overwrite the old port of ${PKGNAME}"; \
		${ECHO_MSG} "      without deleting it first, set the variable \"FORCE_PKG_REGISTER\""; \
		${ECHO_MSG} "      in your environment or the \"${MAKE} install\" command line."; \
		exit 1; \
	fi
.endif
	@if [ `${SH} -c umask` != ${DEF_UMASK} ]; then \
		${ECHO_MSG} "===>  Warning: your umask is \"`${SH} -c umask`"\".; \
		${ECHO_MSG} "      If this is not desired, set it to an appropriate value"; \
		${ECHO_MSG} "      and install this port again by \`\`${MAKE} reinstall''."; \
	fi
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} run-depends
.endif
.if make(real-install)
.if !defined(NO_MTREE)
	@if [ `id -u` = 0 ]; then \
		if [ ! -f ${MTREE_FILE} ]; then \
			${ECHO_MSG} "Error: mtree file \"${MTREE_FILE}\" is missing."; \
			${ECHO_MSG} "Copy it from a suitable location (e.g., /usr/src/etc/mtree) and try again."; \
			exit 1; \
		else \
			if [ ! -d ${PREFIX} ]; then \
				mkdir -p ${PREFIX}; \
			fi; \
			${MTREE_CMD} ${MTREE_ARGS} ${PREFIX}/; \
		fi; \
	else \
		${ECHO_MSG} "Warning: not superuser, can't run mtree."; \
		${ECHO_MSG} "Become root and try again to ensure correct permissions."; \
	fi
.endif
.endif
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} ${.TARGET:S/^real-/pre-/}
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/^real-/pre-/} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/^real-/pre-/}; \
	fi
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} ${.TARGET:S/^real-/do-/}
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} ${.TARGET:S/^real-/post-/}
	@if [ -f ${SCRIPTDIR}/${.TARGET:S/^real-/post-/} ]; then \
		cd ${.CURDIR} && ${SETENV} ${SCRIPTS_ENV} ${SH} \
			${SCRIPTDIR}/${.TARGET:S/^real-/post-/}; \
	fi
.if make(real-install)
	@(newmanpages=`/usr/bin/egrep -h				\
		'^([^/]*/)*man/([^/]*/)?(man[1-9ln]/.*\.[1-9ln]|cat[1-9ln]/.*\.0)(\.gz)?$$'	\
		${PLIST_SRC} || /usr/bin/true`;				\
	if [ X"${MANCOMPRESSED}" != X"" -a X"${MANZ}" = X"" ]; then	\
		${ECHO_MSG} "===>   [Automatic manual page handling]";	\
		${ECHO_MSG} "===>   Decompressing manual pages for ${PKGNAME}";	\
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			${GUNZIP_CMD} ${PREFIX}/$$manpage.gz;		\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi;								\
	if [ X"${MANCOMPRESSED}" = X"" -a X"${MANZ}" != X"" ]; then	\
		${ECHO_MSG} "===>   [Automatic manual page handling]";	\
		${ECHO_MSG} "===>   Compressing manual pages for ${PKGNAME}";	\
		for manpage in $$newmanpages; do			\
			manpage=`${ECHO} $$manpage | ${SED} -e 's|\.gz$$||'`; \
			if [ -L ${PREFIX}/$$manpage ]; then		\
				set - `${FILE} ${PREFIX}/$$manpage`;	\
				shift `expr $$# - 1`;			\
				${LN} -sf $${1}.gz ${PREFIX}/$$manpage.gz; \
				${RM} ${PREFIX}/$$manpage;		\
			else						\
				${GZIP_CMD} ${PREFIX}/$$manpage;	\
			fi;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$manpage";		\
			fi;						\
		done;							\
	fi)
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} ${PLIST}
	@(sos=`/usr/bin/egrep -h 					\
		'^([^/]*/)*lib/lib[^.]+\.so\.[0-9]+\.[0-9]+$$'		\
		${PLIST} || /usr/bin/true`;				\
	if [ X"$$sos" != X"" ]; then					\
		case ${SHLIB_TYPE} in					\
		"ELF")							\
			${ECHO_MSG} "===>   [Automatic ${SHLIB_TYPE} shared object handling]";\
			for so in $$sos; do				\
				so1=`${ECHO} $$so | ${SED} -e 's|\.[0-9]*$$||'`; \
				so2=`${ECHO} $$so1 | ${SED} -e 's|\.[0-9]*$$||'`; \
				case `${GREP} -c "^$$so2$$" ${PLIST}` in \
				0)					\
					${SED} -e "s|^$$so$$|&!$$so2|" -e 'y|!|\n|' ${PLIST} > ${PLIST}.tmp && ${MV} ${PLIST}.tmp ${PLIST}; \
					${ECHO_MSG} "${LN} -sf ${PREFIX}/$$so ${PREFIX}/$$so2"; \
					${LN} -sf ${PREFIX}/$$so ${PREFIX}/$$so2; \
					;;				\
				esac;					\
				case `${GREP} -c "^$$so1$$" ${PLIST}` in \
				0)					\
					${SED} -e "s|^$$so$$|&!$$so1|" -e 'y|!|\n|' ${PLIST} > ${PLIST}.tmp && ${MV} ${PLIST}.tmp ${PLIST}; \
					${ECHO_MSG} "${LN} -sf ${PREFIX}/$$so ${PREFIX}/$$so1";	\
					${LN} -sf ${PREFIX}/$$so ${PREFIX}/$$so1; \
					;;				\
				esac;					\
				if [ X"${PKG_VERBOSE}" != X"" ]; then	\
					${ECHO_MSG} "$$so";		\
				fi;					\
			done						\
			;;						\
		"a.out")						\
			${ECHO_MSG} "===>   [Automatic ${SHLIB_TYPE} shared object handling]";\
			case `${GREP} -c '^@exec ${LDCONFIG}$$' ${PLIST}` in \
			0)						\
				${ECHO} "@exec ${LDCONFIG}" >> ${PLIST}; \
				${ECHO} "@unexec ${LDCONFIG}" >> ${PLIST}; \
				;;					\
			esac;						\
			if [ X"${PKG_VERBOSE}" != X"" ]; then		\
				${ECHO_MSG} "$$sos";			\
				${ECHO_MSG} "Running ${LDCONFIG}";	\
			fi;						\
			${LDCONFIG};					\
			;;						\
		*)							\
			${ECHO_MSG} "No shared libraries for ${MACHINE_ARCH}";	\
			for so in $$sos; do				\
				${SED} -e "s|^$$so$$|@comment No shared objects - &|" ${PLIST} > ${PLIST}.tmp && \
					${MV} ${PLIST}.tmp ${PLIST};	\
			done;						\
			;;						\
		esac;							\
	fi)
.if exists(${PKGDIR}/MESSAGE)
	@${ECHO_MSG} "===>   Please note the following:"
	@${CAT} ${PKGDIR}/MESSAGE
.endif
.if !defined(NO_PKG_REGISTER)
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} fake-pkg
.endif # NO_PKG_REGISTER
.endif
.if !make(real-fetch) \
	&& (!make(real-patch) || !defined(PATCH_CHECK_ONLY)) \
	&& (!make(real-package) || !defined(PACKAGE_NOINSTALL))
	@${TOUCH} ${TOUCH_FLAGS} ${WRKDIR}/.${.TARGET:S/^real-//}_done
.endif

################################################################
# Skeleton targets start here
# 
# You shouldn't have to change these.  Either add the pre-* or
# post-* targets/scripts or redefine the do-* targets.  These
# targets don't do anything other than checking for cookies and
# call the necessary targets/scripts.
################################################################

.if !target(fetch)
fetch:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-fetch
.endif

.if !target(extract)
extract: checksum ${EXTRACT_COOKIE}
.endif

.if !target(patch)
patch: extract ${PATCH_COOKIE}
.endif

.if !target(configure)
configure: patch ${CONFIGURE_COOKIE}
.endif

.if !target(build)
build: configure ${BUILD_COOKIE}
.endif

.if !target(install)
install: build ${INSTALL_COOKIE}
.endif

.if !target(package)
package: install ${PACKAGE_COOKIE}
.endif

${EXTRACT_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-extract
${PATCH_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-patch
${CONFIGURE_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-configure
${BUILD_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-build
${INSTALL_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-install
${PACKAGE_COOKIE}:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} real-package

# And call the macros

real-fetch: _PORT_USE
real-extract: _PORT_USE
	@${ECHO_MSG} "===>  Extracting for ${PKGNAME}"
real-patch: _PORT_USE
	@${ECHO_MSG} "===>  Patching for ${PKGNAME}"
real-configure: _PORT_USE
	@${ECHO_MSG} "===>  Configuring for ${PKGNAME}"
real-build: _PORT_USE
	@${ECHO_MSG} "===>  Building for ${PKGNAME}"
real-install: _PORT_USE
	@${ECHO_MSG} "===>  Installing for ${PKGNAME}"
real-package: _PORT_USE

# Empty pre-* and post-* targets, note we can't use .if !target()
# in the _PORT_USE macro

.for name in fetch extract patch configure build install package

.if !target(pre-${name})
pre-${name}:
	@${DO_NADA}
.endif

.if !target(post-${name})
post-${name}:
	@${DO_NADA}
.endif

.endfor

# Checkpatch
#
# Special target to verify patches

.if !target(checkpatch)
checkpatch:
	@cd ${.CURDIR} && ${MAKE} PATCH_CHECK_ONLY=yes ${.MAKEFLAGS} patch
.endif

# Reinstall
#
# Special target to re-run install

.if !target(reinstall)
reinstall:
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
	@DEPENDS_TARGET=${DEPENDS_TARGET} ${MAKE} install
.endif

# Deinstall
#
# Special target to remove installation

.if !target(deinstall)
deinstall:
	@${ECHO_MSG} "===> Deinstalling for ${PKGNAME}"
.ifdef PKG_VERBOSE
	@pkg_delete -v -f ${PKGNAME}
.else
	@pkg_delete -f ${PKGNAME}
.endif
	@${RM} -f ${INSTALL_COOKIE} ${PACKAGE_COOKIE}
.endif

.endif # __ARCH_OK
       # The functions below may be useful even if _ARCH_OK is not set


################################################################
# Some more targets supplied for users' convenience
################################################################

# Cleaning up

.if !target(pre-clean)
pre-clean:
	@${DO_NADA}
.endif

.if !target(clean)
clean: pre-clean
.if !defined(NOCLEANDEPENDS)
	@${MAKE} clean-depends
.endif
	@${ECHO_MSG} "===>  Cleaning for ${PKGNAME}"
.if !defined(NO_WRKDIR)
.if  defined(WRKOBJDIR)
	@${RM} -rf ${WRKOBJDIR}/${PORTSUBDIR}
	@${RM} -f ${WRKDIR}
.else
	@if [ -d ${WRKDIR} ]; then \
		if [ -w ${WRKDIR} ]; then \
			${RM} -rf ${WRKDIR}; \
		else \
			${ECHO_MSG} "===>   ${WRKDIR} not writable, skipping"; \
		fi; \
	fi
.endif
.else
	@${RM} -f ${WRKDIR}/.*_done
.endif
.endif

.if !target(pre-distclean)
pre-distclean:
	@${DO_NADA}
.endif

.if !target(distclean)
distclean: pre-distclean clean
	@${ECHO_MSG} "===>  Dist cleaning for ${PKGNAME}"
	@(if [ -d ${_DISTDIR} ]; then \
		cd ${_DISTDIR}; \
		${RM} -f ${DISTFILES} ${PATCHFILES}; \
	fi)
.if defined(DIST_SUBDIR)
	-@${RMDIR} ${_DISTDIR}  
.endif
.endif

# Prints out a list of files to fetch (useful to do a batch fetch)

# are we called from bsd.pkg.subdir.mk (i.e. do we scan all dirs anyway)? XXX
.ifdef(_THISDIR_)
RECURSIVE_FETCH_LIST?=	NO
.else
RECURSIVE_FETCH_LIST?=	YES
.endif

.if !target(fetch-list)
fetch-list:
	@${MAKE} fetch-list-recursive RECURSIVE_FETCH_LIST=${RECURSIVE_FETCH_LIST} | sort -u
.endif # !target(fetch-list)

.if !target(fetch-list-recursive)
fetch-list-recursive:
	@${MAKE} fetch-list-one-pkg
.if ${RECURSIVE_FETCH_LIST} != "NO"
	@for dir in `${ECHO} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${DEPENDS} ${RUN_DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u` ; do \
		(cd $$dir; ${MAKE} fetch-list-recursive; ); \
	done
.endif # ${RECURSIVE_FETCH_LIST} != "NO"
.endif # !target(fetch-list-recursive)

.if !target(fetch-list-one-pkg)
fetch-list-one-pkg:
	@${MKDIR} ${_DISTDIR}
	@[ -z "${_DISTDIR}" ] || ${ECHO} "${MKDIR} ${_DISTDIR}"
	@(cd ${_DISTDIR}; \
	for file in ${DISTFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			${ECHO} -n "cd ${_DISTDIR} && [ -f $$file -o -f `${BASENAME} $$file` ] || " ; \
			for site in ${MASTER_SITES} ; do \
				${ECHO} -n ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO} "echo $${file} not fetched" ; \
		fi \
	done)
.if defined(PATCHFILES)
	@(cd ${_DISTDIR}; \
	for file in ${PATCHFILES}; do \
		if [ ! -f $$file -a ! -f `${BASENAME} $$file` ]; then \
			${ECHO} -n "cd ${_DISTDIR} && [ -f $$file -o -f `${BASENAME} $$file` ] || " ; \
			for site in ${PATCH_SITES}; do \
				${ECHO} -n ${FETCH_CMD} ${FETCH_BEFORE_ARGS} $${site}$${file} "${FETCH_AFTER_ARGS}" '|| ' ; \
			done; \
			${ECHO} "echo $${file} not fetched" ; \
		fi \
	done)
.endif # defined(PATCHFILES)
.endif # !target(fetch-list-one-pkg)

# Checksumming utilities

.if !target(makesum)
makesum: fetch
	@${MKDIR} ${FILESDIR}
	@if [ -f ${MD5_FILE} ]; then ${RM} -f ${MD5_FILE}; fi
	@(cd ${DISTDIR}; \
	 for file in ${_CKSUMFILES}; do \
		${MD5} $$file >> ${MD5_FILE}; \
	 done)
	@for file in ${_IGNOREFILES}; do \
		${ECHO} "MD5 ($$file) = IGNORE" >> ${MD5_FILE}; \
	done
.endif

.if !target(checksum)
checksum: fetch
	@if [ ! -f ${MD5_FILE} ]; then \
		${ECHO_MSG} ">> No MD5 checksum file."; \
	else \
		(cd ${DISTDIR}; OK="true"; \
		  for file in ${_CKSUMFILES}; do \
			CKSUM=`${MD5} < $$file`; \
			CKSUM2=`${AWK} '$$1 == "MD5" && $$2 == "\('$$file'\)"{print $$4;}' ${MD5_FILE}`; \
			if [ "$$CKSUM2" = "" ]; then \
				${ECHO_MSG} ">> No checksum recorded for $$file."; \
				OK="false"; \
			elif [ "$$CKSUM2" = "IGNORE" ]; then \
				${ECHO_MSG} ">> Checksum for $$file is set to IGNORE in md5 file even though"; \
				${ECHO_MSG} "   the file is not in the "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			elif [ "$$CKSUM" = "$$CKSUM2" ]; then \
				${ECHO_MSG} ">> Checksum OK for $$file."; \
			else \
				${ECHO_MSG} ">> Checksum mismatch for $$file."; \
				OK="false"; \
			fi; \
		  done; \
		  for file in ${_IGNOREFILES}; do \
			CKSUM2=`${AWK} '$$1 == "MD5" && $$2 == "\('$$file'\)"{print $$4;}' ${MD5_FILE}`; \
			if [ "$$CKSUM2" = "" ]; then \
				${ECHO_MSG} ">> No checksum recorded for $$file, file is in "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			elif [ "$$CKSUM2" != "IGNORE" ]; then \
				${ECHO_MSG} ">> Checksum for $$file is not set to IGNORE in md5 file even though"; \
				${ECHO_MSG} "   the file is in the "'$$'"{IGNOREFILES} list."; \
				OK="false"; \
			fi; \
		  done; \
		  if [ "$$OK" != "true" ]; then \
			${ECHO_MSG} "Make sure the Makefile and md5 file (${MD5_FILE})"; \
			${ECHO_MSG} "are up to date.  If you want to override this check, type"; \
			${ECHO_MSG} "\"${MAKE} NO_CHECKSUM=yes [other args]\"."; \
			exit 1; \
		  fi) ; \
	fi
.endif

################################################################
# The special package-building targets
# You probably won't need to touch these
################################################################

HTMLIFY=	${SED} -e 's/&/\&amp;/g' -e 's/>/\&gt;/g' -e 's/</\&lt;/g'

# Set to YES by the README.html target (and passed via depends-list
# and package-depends)
.ifndef PACKAGE_NAME_AS_LINK
PACKAGE_NAME_AS_LINK=NO
.endif # PACKAGE_NAME_AS_LINK


# Nobody should want to override this unless PKGNAME is simply bogus.

.if !target(package-name)
package-name:
.if (${PACKAGE_NAME_AS_LINK} == "YES")
	@${ECHO} '<A HREF="../../'`${MAKE} package-path | ${HTMLIFY}`'/README.html">'`echo ${PKGNAME} | ${HTMLIFY}`'</A>'
.else
	@${ECHO} '${PKGNAME}'
.endif # PACKAGE_NAME_AS_LINK != ""
.endif # !target(package-name)

.if !target(package-path)
package-path:
	@pwd | sed s@`cd ${PKGSRCDIR} ; pwd`/@@g
.endif

# Show (recursively) all the packages this package depends on.

.if !target(package-depends)
package-depends:
	@for dir in `${ECHO} ${DEPENDS} ${RUN_DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u`; do \
		if [ -d $$dir ]; then \
			(cd $$dir ; ${MAKE} package-name package-depends PACKAGE_NAME_AS_LINK=${PACKAGE_NAME_AS_LINK}); \
		else \
			${ECHO_MSG} "Warning: \"$$dir\" non-existent -- @pkgdep registration incomplete" >&2; \
		fi; \
	done
.endif

# Build a package but don't check the package cookie

.if !target(repackage)
repackage: pre-repackage package

pre-repackage:
	@${RM} -f ${PACKAGE_COOKIE}
.endif

# Build a package but don't check the cookie for installation, also don't
# install package cookie

.if !target(package-noinstall)
package-noinstall:
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} PACKAGE_NOINSTALL=yes real-package
.endif

################################################################
# Dependency checking
################################################################

.if !target(depends)
depends: misc-depends
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} fetch-depends
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} build-depends
	@cd ${.CURDIR} && ${MAKE} ${.MAKEFLAGS} run-depends

.if make(fetch-depends)
DEPENDS_TMP+=	${FETCH_DEPENDS}
.endif

.if make(build-depends)
DEPENDS_TMP+=	${BUILD_DEPENDS}
.endif

.if make(run-depends)
DEPENDS_TMP+=	${RUN_DEPENDS}
.endif

_DEPENDS_USE:	.USE
.if defined(DEPENDS_TMP)
.if !defined(NO_DEPENDS)
	@for i in ${DEPENDS_TMP}; do \
		prog=`${ECHO} $$i | ${SED} -e 's/:.*//'`; \
		dir=`${ECHO} $$i | ${SED} -e 's/[^:]*://'`; \
		if expr "$$dir" : '.*:' > /dev/null; then \
			target=`${ECHO} $$dir | ${SED} -e 's/.*://'`; \
			dir=`${ECHO} $$dir | ${SED} -e 's/:.*//'`; \
		else \
			target=${DEPENDS_TARGET}; \
		fi; \
		found=not; \
		if expr "$$prog" : '.*/' >/dev/null; then \
			if [ -e "$$prog" ]; then \
				${ECHO_MSG} "===>  ${PKGNAME} depends on file: $$prog - found"; \
				found=""; \
			else \
				${ECHO_MSG} "===>  ${PKGNAME} depends on file: $$prog - not found"; \
			fi; \
		else \
			for d in `echo $$PATH | tr ':' ' '`; do \
				if [ -x $$d/$$prog ]; then \
					found="$$d/$$prog"; \
					break; \
				fi \
			done; \
			${ECHO_MSG} "===>  ${PKGNAME} depends on executable: $$prog - $$found found"; \
		fi; \
		if [ X"$$found" = Xnot ]; then \
			${ECHO_MSG} "===>  Verifying $$target for $$prog in $$dir"; \
			if [ ! -d "$$dir" ]; then \
				${ECHO_MSG} ">> No directory for $$prog.  Skipping.."; \
			else \
				(cd $$dir; ${MAKE} ${.MAKEFLAGS} $$target) ; \
				${ECHO_MSG} "===>  Returning to build of ${PKGNAME}"; \
			fi; \
		fi; \
	done
.endif
.else
	@${DO_NADA}
.endif

fetch-depends:	_DEPENDS_USE
build-depends:	_DEPENDS_USE
run-depends:	_DEPENDS_USE

misc-depends:
.if defined(DEPENDS)
.if !defined(NO_DEPENDS)
	@(/bin/sh -f -c 'for dir in ${DEPENDS}; do			\
		package="`${ECHO} \"$$dir\" | ${SED} -e s/:.\*//`";	\
		dir="`${ECHO} \"$$dir\" | ${SED} -e s/.\*://`";		\
		found=`/usr/sbin/pkg_info -e "$$package"`;		\
		if [ $$? -eq 0 ]; then					\
			${ECHO_MSG} "===>  ${PKGNAME} depends on installed package: $$package - $$found found";	\
		else							\
			${ECHO_MSG} "===>  ${PKGNAME} depends on package: $$package";	\
			target=${DEPENDS_TARGET};			\
			${ECHO_MSG} "===>  Verifying $$target for $$dir"; \
			if [ ! -d $$dir ]; then				\
				${ECHO_MSG} ">> No directory for $$dir.  Skipping.."; \
			else						\
				(cd $$dir; ${MAKE} ${.MAKEFLAGS} $$target);	\
			fi						\
		fi							\
	done')
.endif
.else
	@${DO_NADA}
.endif

.endif

.if !target(clean-depends)
clean-depends:
.if defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) \
	|| defined(DEPENDS) || defined(RUN_DEPENDS)
	@for dir in `${ECHO} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${DEPENDS} ${RUN_DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u`; do \
		if [ -d $$dir ] ; then \
			(cd $$dir; ${MAKE} NOCLEANDEPENDS=yes clean clean-depends); \
		fi \
	done
.endif
.endif

.if !target(depends-list)
depends-list:
	@for dir in `${ECHO} ${FETCH_DEPENDS} ${BUILD_DEPENDS} ${DEPENDS} | ${TR} '\040' '\012' | ${SED} -e 's/^[^:]*://' -e 's/:.*//' | sort -u`; do \
		(cd $$dir; ${MAKE} package-name depends-list PACKAGE_NAME_AS_LINK=${PACKAGE_NAME_AS_LINK}; ); \
	done
.endif

# The following assumes that PACKAGES is set like the following:
# PACKAGES= /usr/pkgsrc/packages/`uname -r`/${MACHINE_ARCH}
# i.e. contain OS version and arch name as subdirs
.if !target(binpkg-list)
binpkg-list:
	@cd ${PACKAGES}/../.. ; \
	for i in */* ; \
	do \
		f=$$i/${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX} ; \
		if [ -f $$f ]; then \
			echo $$i; \
		fi ; \
	done | awk ' 											\
		BEGIN 												\
		{ 													\
			FS="/";											\
		} 													\
		{													\
			rel=$$1 ; 										\
			arch=$$2 ; 										\
			if (arch != "m68k"){							\
				if (arch in f) 								\
					f[arch] = "%%BIN_PREREL%%" rel "/" arch "%%BIN_MEDREL%%" rel "%%BIN_POSTREL%%, " f[arch];					\
				else 											\
					f[arch] = "%%BIN_PREREL%%" rel "/" arch "%%BIN_MEDREL%%" rel "%%BIN_POSTREL%%";								\
			}												\
		} 													\
		END 												\
		{ 													\
			for (rel in	f) {								\
				print "%%BIN_PREARCH%%" rel "%%BIN_POSTARCH%% (NetBSD " f[rel] ")";						\
			}												\
		} 													\
	'
.endif

################################################################
# Everything after here are internal targets and really
# shouldn't be touched by anybody but the release engineers.
################################################################

# This target generates an index entry suitable for aggregation into
# a large index.  Format is:
#
# distribution-name|port-path|installation-prefix|comment| \
#  description-file|maintainer|categories|build deps|run deps|for arch
#
.if !target(describe)
describe:
	@${ECHO} -n "${PKGNAME}|${.CURDIR}|"; \
	${ECHO} -n "${PREFIX}|"; \
	if [ -f ${COMMENT} ]; then \
		${ECHO} -n "`${CAT} ${COMMENT}`"; \
	else \
		${ECHO} -n "** No Description"; \
	fi; \
	if [ -f ${DESCR} ]; then \
		${ECHO} -n "|${DESCR}"; \
	else \
		${ECHO} -n "|/dev/null"; \
	fi; \
	${ECHO} -n "|${MAINTAINER}|${CATEGORIES}|"; \
	case "A${FETCH_DEPENDS}B${BUILD_DEPENDS}C${DEPENDS}D" in \
		ABCD) ;; \
		*) cd ${.CURDIR} && ${ECHO} -n `${MAKE} depends-list|sort -u`;; \
	esac; \
	${ECHO} -n "|"; \
	case "A${RUN_DEPENDS}B${DEPENDS}C" in \
		ABC) ;; \
		*) cd ${.CURDIR} && ${ECHO} -n `${MAKE} package-depends|sort -u`;; \
	esac; \
	${ECHO} -n "|"; \
	if [ "${ONLY_FOR_ARCHS}" = "" ]; then \
		${ECHO} -n "any"; \
	else \
		${ECHO} -n "${ONLY_FOR_ARCHS}"; \
	fi; \
	${ECHO} ""
.endif

.if !target(readmes)
readmes:	readme
.endif

.if !target(readme)
readme:
	@if [ -f README.html ]; then  mv -f README.html README.html.BAK ; fi
	@cd ${.CURDIR} && ${MAKE} README.html
.endif

.if (${OPSYS} == "NetBSD")
README_NAME=	${TEMPLATES}/README.pkg
.else
README_NAME=	${TEMPLATES}/README.port
.endif

# set up the correct license information as a sed expression
.ifdef LICENSE
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%|<p>Please note that this package has a ${LICENSE} license.</p>|'
.else
SED_LICENSE_EXPR=       -e 's|%%LICENSE%%||'
.endif

README.html:
	@${MAKE} depends-list PACKAGE_NAME_AS_LINK=YES | sort -u >> $@.tmp1
	@[ -s $@.tmp1 ] || echo "<I>(none)</I>" >> $@.tmp1
	@${MAKE} package-depends PACKAGE_NAME_AS_LINK=YES | sort -u >> $@.tmp2
	@[ -s $@.tmp2 ] || echo "<I>(none)</I>" >> $@.tmp2
	@${ECHO} ${PKGNAME} | ${HTMLIFY} >> $@.tmp3
	@${MAKE} binpkg-list  >> $@.tmp4
	@[ -s $@.tmp4 ] || echo "<I>(no precompiled binaries available)</I>" >> $@.tmp4
	@${CAT} ${README_NAME} | \
		${SED} -e 's|%%PORT%%|'"`${MAKE} package-path | ${HTMLIFY}`"'|g' \
			-e '/%%PKG%%/r$@.tmp3' \
			-e '/%%PKG%%/d' \
			${SED_LICENSE_EXPR} \
			-e '/%%COMMENT%%/r${PKGDIR}/COMMENT' \
			-e '/%%COMMENT%%/d' \
			-e '/%%BUILD_DEPENDS%%/r$@.tmp1' \
			-e '/%%BUILD_DEPENDS%%/d' \
			-e '/%%RUN_DEPENDS%%/r$@.tmp2' \
			-e '/%%RUN_DEPENDS%%/d' \
			-e '/%%BIN_PKGS%%/r$@.tmp4' \
			-e '/%%BIN_PKGS%%/d' \
		| ${SED} \
			-e 's@%%BIN_PREREL%%@<A HREF="ftp://ftp.netbsd.org/pub/NetBSD/packages/@g' \
			-e 's@%%BIN_MEDREL%%@/${PKGREPOSITORYSUBDIR}/${PKGNAME}${PKG_SUFX}">@g' \
			-e 's@%%BIN_POSTREL%%@</A>@g' \
			-e 's@%%BIN_PREARCH%%@<LI> @g' \
			-e 's@%%BIN_POSTARCH%%@@g' \
		>> $@.tmp
	@if cmp -s $@.tmp $@.BAK ; then \
		mv $@.BAK $@ ; \
		rm $@.tmp ; \
	else \
		${ECHO_MSG} "===>  Creating README.html for ${_THISDIR_}${PKGNAME}" ; \
		mv $@.tmp $@ ; \
		rm -f $@.BAK ; \
	fi
	@rm -f $@.tmp1 $@.tmp2 $@.tmp3 $@.tmp4

.if !target(print-depends-list)
print-depends-list:
.if defined(FETCH_DEPENDS) || defined(BUILD_DEPENDS) || defined(DEPENDS)
	@${ECHO} -n 'This port requires package(s) "'
	@${ECHO} -n `${MAKE} depends-list | sort -u`
	@${ECHO} '" to build.'
.endif
.endif

.if !target(print-package-depends)
print-package-depends:
.if defined(RUN_DEPENDS) || defined(DEPENDS)
	@${ECHO} -n 'This port requires package(s) "'
	@${ECHO} -n `${MAKE} package-depends | sort -u`
	@${ECHO} '" to run.'
.endif
.endif

# Fake installation of package so that user can pkg_delete it later.
# Also, make sure that an installed port is recognized correctly in
# accordance to the @pkgdep directive in the packing lists

.if !target(fake-pkg)
fake-pkg: ${PLIST}
	@if [ ! -f ${PLIST} -o ! -f ${COMMENT} -o ! -f ${DESCR} ]; then ${ECHO} "** Missing package files for ${PKGNAME} - installation not recorded."; exit 1; fi
	@if [ ! -d ${PKG_DBDIR} ]; then ${RM} -f ${PKG_DBDIR}; ${MKDIR} ${PKG_DBDIR}; fi
.if defined(FORCE_PKG_REGISTER)
	@${RM} -rf ${PKG_DBDIR}/${PKGNAME}
.endif
	@if [ ! -d ${PKG_DBDIR}/${PKGNAME} ]; then \
		${ECHO_MSG} "===>  Registering installation for ${PKGNAME}"; \
		${MKDIR} ${PKG_DBDIR}/${PKGNAME}; \
		${PKG_CMD} ${PKG_ARGS} -O ${PKGFILE} > ${PKG_DBDIR}/${PKGNAME}/+CONTENTS; \
		${CP} ${DESCR} ${PKG_DBDIR}/${PKGNAME}/+DESC; \
		${CP} ${COMMENT} ${PKG_DBDIR}/${PKGNAME}/+COMMENT; \
		if [ -f ${PKGDIR}/INSTALL ]; then \
			${CP} ${PKGDIR}/INSTALL ${PKG_DBDIR}/${PKGNAME}/+INSTALL; \
		fi; \
		if [ -f ${PKGDIR}/DEINSTALL ]; then \
			${CP} ${PKGDIR}/DEINSTALL ${PKG_DBDIR}/${PKGNAME}/+DEINSTALL; \
		fi; \
		if [ -f ${PKGDIR}/REQ ]; then \
			${CP} ${PKGDIR}/REQ ${PKG_DBDIR}/${PKGNAME}/+REQUIRE; \
		fi; \
		if [ -f ${PKGDIR}/MESSAGE ]; then \
			${CP} ${PKGDIR}/MESSAGE ${PKG_DBDIR}/${PKGNAME}/+DISPLAY; \
		fi; \
		for dep in `${MAKE} package-depends ECHO_MSG=${TRUE} | sort -u`; do \
			if [ -d ${PKG_DBDIR}/$$dep ]; then \
				if ! ${GREP} ^${PKGNAME}$$ ${PKG_DBDIR}/$$dep/+REQUIRED_BY \
					>/dev/null 2>&1; then \
					${ECHO} ${PKGNAME} >> ${PKG_DBDIR}/$$dep/+REQUIRED_BY; \
				fi; \
			fi; \
		done; \
	fi
.endif

# Depend is generally meaningless for arbitrary ports, but if someone wants
# one they can override this.  This is just to catch people who've gotten into
# the habit of typing `${MAKE} depend all install' as a matter of course.
#
.if !target(depend)
depend:
.endif

# Same goes for tags
.if !target(tags)
tags:
.endif

# generate ${PLIST} from ${PLIST_SRC} by:
# - fixing list of man-pages according to MANCOMPRESSED/MANZ
#   (we don't take any notice of MANCOMPRESSED as many packages have .gz
#   pages in PLIST even when they install manpages without compressing them)
# - substituting ${OPSYS}, ${MACHINE_ARCH} and ${MACHINE_GNU_ARCH}

${PLIST}: ${PLIST_SRC}
	@if [ -z "${PLIST_SRC}" ] ; then \
		${ECHO} "No ${PKGDIR}/PLIST, and no ${PKGDIR}/PLIST-{mi,md.shared,md.static}" ; \
		${ECHO} "The package Makefile must make ${PLIST} by setting PLIST_SRC!" ; \
	fi
.if defined(MANZ)
	@if [ ! -z "${PLIST_SRC}" ] ; then \
		${CAT} ${PLIST_SRC} | ${SED} \
			-e 's|\(^\([^/]*/\)*man/\([^/]*/\)\{0,1\}man[1-9ln]/.*[1-9ln]$$\)|\1.gz|' \
			-e 's|\(^\([^/]*/\)*man/\([^/]*/\)\{0,1\}cat[1-9ln]/.*[0-9ln]$$\)|\1.gz|' \
			-e 's|\$${OPSYS}|${OPSYS}|g' \
			-e 's/\$${MACHINE_ARCH}/'${MACHINE_ARCH}'/g' \
			-e 's/\$${MACHINE_GNU_ARCH}/'${MACHINE_GNU_ARCH}'/g' \
			>${PLIST} ; \
	fi
.else   # !MANZ
	@if [ ! -z "${PLIST_SRC}" ] ; then \
		${CAT} ${PLIST_SRC} | ${SED} \
			-e 's|\(^\([^/]*/\)*man/\([^/]*/\)\{0,1\}man[1-9ln]/.*[1-9ln]\)\.gz$$|\1|' \
			-e 's|\(^\([^/]*/\)*man/\([^/]*/\)\{0,1\}cat[1-9ln]/.*[0-9ln]\)\.gz$$|\1|' \
			-e 's|\$${OPSYS}|${OPSYS}|g' \
			-e 's/\$${MACHINE_ARCH}/'${MACHINE_ARCH}'/g' \
			-e 's/\$${MACHINE_GNU_ARCH}/'${MACHINE_GNU_ARCH}'/g' \
			>${PLIST} ; \
	fi
.endif  # MANZ
