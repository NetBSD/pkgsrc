# $NetBSD: Makefile,v 1.117 2024/05/06 08:24:05 jperkin Exp $

DISTNAME=	ncurses-6.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=ncurses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://invisible-island.net/ncurses/ncurses.html
LICENSE=	mit
COMMENT=	CRT screen handling and optimization package

CONFLICTS+=	ncursesw-[0-9]*
SUPERSEDES+=	ncursesw-[0-9]*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config tbl

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-libtool
CONFIGURE_ARGS+=	--enable-bsdpad
CONFIGURE_ARGS+=	--enable-widec
CONFIGURE_ARGS+=	--disable-overwrite
CONFIGURE_ARGS+=	--disable-lib-suffixes
CONFIGURE_ARGS+=	--with-cxx-binding
CONFIGURE_ARGS+=	--enable-pc-files
CONFIGURE_ARGS+=	--with-pkg-config-libdir=${PREFIX}/lib/pkgconfig
CONFIGURE_ARGS+=	--without-ada
CONFIGURE_ARGS+=	--without-gpm
CONFIGURE_ARGS+=	--with-manpage-format=normal
CONFIGURE_ARGS+=	--without-manpage-renames
CONFIGURE_ARGS+=	--with-default-terminfo-dir=${PREFIX}/${TERMINFODIR}
CONFIGURE_ARGS+=	--with-terminfo-dirs=${PREFIX}/${TERMINFODIR}

# These libraries are renamed as there were apparently issues back in 2016 when
# they matched the same names as builtin NetBSD libraries.  It would be good to
# verify that this is still a problem
#
CONFIGURE_ARGS+=	--with-form-libname=gnuform
CONFIGURE_ARGS+=	--with-menu-libname=gnumenu
CONFIGURE_ARGS+=	--with-panel-libname=gnupanel

CONFIGURE_ARGS.Darwin+=	--disable-mixed-case
CONFIGURE_ARGS.SunOS+=	--disable-const

TERMINFODIR=		share/terminfo

SUBST_CLASSES+=		rpath
SUBST_FILES.rpath+=	misc/ncurses-config
SUBST_STAGE.rpath=	post-configure
SUBST_SED.rpath+=	-e "s|-L\\(.libdir\\)|${COMPILER_RPATH_FLAG}\\1 -L\\1|"
SUBST_MESSAGE.rpath=	Fixing rpath in ncurses-config.

SUBST_CLASSES+=		setenv
SUBST_FILES.setenv=	misc/run_tic.in
SUBST_STAGE.setenv=	pre-configure
SUBST_VARS.setenv=	SETENV

.include "../../mk/bsd.prefs.mk"

.if ${USE_CROSS_COMPILE:U:tl} == yes
TOOL_DEPENDS+=		ncurses-[0-9]*:../../devel/ncurses
CONFIGURE_ENV+=		BUILD_CC=${NATIVE_CC:Q}
CONFIGURE_ENV+=		ac_cv_path_TIC_PATH=${TOOLBASE:Q}/bin/tic
ALL_ENV+=		TIC_PATH=${TOOLBASE:Q}/bin/tic
.endif

# If there's no native tbl(1) then the tools infrastructure would pull in
# groff, causing various circular dependencies.
.if defined(TOOLS_TBL)
CONFIGURE_ARGS+=	--with-manpage-tbl
.else
USE_TOOLS:=		${USE_TOOLS:Ntbl}
CONFIGURE_ARGS+=	--without-manpage-tbl
.endif

.include "../../mk/compiler.mk"

# Fix build under FreeBSD 10.2
.if !empty(PKGSRC_COMPILER:Mclang)
CONFIGURE_ENV+=		ac_cv_c_compiler_gnu=no
CONFIGURE_ENV+=		ac_cv_cxx_compiler_gnu=no
.endif

.if ${CC_VERSION:Mgcc-5.*}
# Inhibit generation of line markers in the output from the preprocessor
# https://gcc.gnu.org/bugzilla/show_bug.cgi?id=60723
CPPFLAGS+=	-P
.endif

# This prevents tic from writing into ~/.terminfo
INSTALLATION_DIRS+=	${TERMINFODIR}

# TERMINFODIR entries are generated automatically.
PLIST_SRC=		${PKGDIR}/PLIST ${WRKDIR}/PLIST.terminfo
PRINT_PLIST_AWK+=	/${TERMINFODIR:S|/|\\/|g}/ { next; }

CHECK_WRKREF_SKIP+=	man/man?/*

post-configure:
	cd ${WRKSRC}/man;					\
	for f in *.1m; do					\
		mv -f $${f} `${BASENAME} $${f} .1m`.1; 	\
	done;							\
	for f in *.3x; do					\
		mv -f $${f} `${BASENAME} $${f} .3x`.3; 	\
	done

post-install:
.if ${OPSYS} == "Darwin"
	# Clashes with "a" versions on case-insensitive file systems
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/32/2621A
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/68/hp2621A
	${RM} -f ${DESTDIR}${PREFIX}/${TERMINFODIR}/68/hp70092A
.endif
	${FIND} ${DESTDIR}${PREFIX}/${TERMINFODIR} -type f -print | ${SORT} | \
		${SED} -e "s,^${DESTDIR}${PREFIX}/,," >${WRKDIR}/PLIST.terminfo
	${RM} -f ${DESTDIR}${PREFIX}/lib/terminfo

.include "../../mk/bsd.pkg.mk"
