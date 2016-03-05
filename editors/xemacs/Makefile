# $NetBSD: Makefile,v 1.115 2016/03/05 11:28:28 jperkin Exp $

PKGNAME?=	${DISTNAME}
COMMENT?=	XEmacs text editor version 21

DISTNAME=	xemacs-21.4.23
PKGREVISION=	3
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=${DISTNAME:C/[.][^.]*$//}/}

MAINTAINER=	hauke@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/
LICENSE=	gnu-gpl-v2

CONFLICTS+=	gnuserv-[0-9]*
CONFLICTS+=	xemacs-[0-9]*
CONFLICTS+=	xemacs-nox11-[0-9]*

BROKEN_ON_PLATFORM=	*-*-mips*	# fails purespace dumping

USE_TOOLS+=	makeinfo

HAS_CONFIGURE=		yes

DIST_SUBDIR=		xemacs
PLIST_SUBST+=		DISTNAME=${DISTNAME:Q}
FILES_SUBST+=		DISTNAME=${DISTNAME:Q}
MESSAGE_SUBST+=		DISTNAME=${DISTNAME:Q}
INFO_FILES=		yes

.if defined(MANZ)
PLIST_SUBST+=		ELSUFX='.gz'
.else
PLIST_SUBST+=		ELSUFX=''
.endif

.include "options.mk"

CONFIGURE_ARGS+=	${MACHINE_GNU_PLATFORM}
CONFIGURE_ARGS+=	--prefix=${PREFIX:Q}
CONFIGURE_ARGS+=	--mandir=${PREFIX:Q}/${PKGMANDIR:Q}/man1
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule=yes
CONFIGURE_ARGS+=	--with-msw=no
CONFIGURE_ARGS+=	--pdump
CFLAGS+=		-Dunix

# Use terminfo on NetBSD-6 and newer.
# We cannot use terminfo.*.mk as XEmacs enforces a link to termcap,
# but this is fine for us.
.if (${OPSYS} == "NetBSD") && exists(/usr/include/term.h)
CPPFLAGS+=	-DTERMINFO
.endif

.if ${X11_TYPE} != "modular"
INFOPATH=		${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
.else
INFOPATH=		${PREFIX}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
.endif
CONFIGURE_ARGS+=	--infopath=${INFOPATH:Q}

.if ${OPSYS} == "SunOS"
.  if !exists(/usr/demo/SOUND/libaudio.a) && \
      !exists(/usr/demo/SOUND/lib/libaudio.a)
CONFIGURE_ARGS+=	--with_sound=none
.  endif
.endif

.if (${OPSYS} == "DragonFly") && exists(/usr/lib/crtn.o)
CPPFLAGS+=		-DDFLY_CRT_USRLIB
.endif

CHECK_WRKREF_SKIP=	bin/xemacs*
REPLACE_SH=		etc/check_cygwin_setup.sh

LIBDIR=			${PREFIX}/lib/${DISTNAME}
ARCHLIBDIR=		${LIBDIR}/${MACHINE_GNU_PLATFORM}

# The portable dumper creates a dump file with a build ID in its name
GENERATE_PLIST+=	${ECHO} bin/${DISTNAME}-`${WRKSRC}/src/xemacs -sd`.dmp ;

# This list overrides variables used in the source Makefiles at install
# time to allow for ${DESTDIR}-style installation.  This variables list
# is pulled from the ``mkdir'' target of Makefile.in.in.
#
INSTALL_MAKE_FLAGS+=	archlibdir=${DESTDIR}${ARCHLIBDIR}
INSTALL_MAKE_FLAGS+=	bindir=${DESTDIR}${PREFIX}/bin
INSTALL_MAKE_FLAGS+=	datadir=${DESTDIR}${PREFIX}/lib
INSTALL_MAKE_FLAGS+=	docdir=${DESTDIR}${ARCHLIBDIR}
INSTALL_MAKE_FLAGS+=	etcdir=${DESTDIR}${LIBDIR}/etc
INSTALL_MAKE_FLAGS+=	exec_prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	infodir=${DESTDIR}${LIBDIR}/info
INSTALL_MAKE_FLAGS+=	libdir=${DESTDIR}/lib
INSTALL_MAKE_FLAGS+=	lispdir=${DESTDIR}${LIBDIR}/lisp
INSTALL_MAKE_FLAGS+=	mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
INSTALL_MAKE_FLAGS+=	moduledir=${DESTDIR}${ARCHLIBDIR}/modules
INSTALL_MAKE_FLAGS+=	pkgdir=${DESTDIR}${LIBDIR}/lisp
INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX}
INSTALL_MAKE_FLAGS+=	sitelispdir=${DESTDIR}${PREFIX}/lib/xemacs/site-lisp
INSTALL_MAKE_FLAGS+=	sitemoduledir=${DESTDIR}${PREFIX}/lib/xemacs/site-modules

post-extract:
	cp ${FILESDIR}/dragonfly.h ${WRKSRC}/src/s/

pre-build:
	rm -f ${WRKSRC}/etc/ctags.1.orig

post-install:
	${INSTALL_DATA} ${WRKSRC}/Installation ${DESTDIR}${LIBDIR}/etc/
.if defined(MANZ)
	find ${DESTDIR}${LIBDIR} -name "*.el" -type f -print | xargs ${GZIP_CMD}
.endif

.include "../../databases/gdbm/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
