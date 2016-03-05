# $NetBSD: Makefile,v 1.89 2016/03/05 11:28:28 jperkin Exp $

PKGNAME?=	${DISTNAME}
COMMENT?=	*BETA* XEmacs text editor version ${PKGVERSION_NOREV}

DISTNAME=	xemacs-21.5.27
EMACSVERSION=	21.5-b27
EMACS_DISTNAME=	xemacs-${EMACSVERSION}
PKGREVISION=	23
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_XEMACS:=${DISTNAME:C/[.][^.]*$//}/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.xemacs.org/

CONFLICTS+=	gnuclient-[0-9]*
CONFLICTS+=	xemacs-[0-9]*
CONFLICTS+=	xemacs-nox11-[0-9]*

.if ${MACHINE_ARCH} == "arm" || ${MACHINE_ARCH} == "arm32"
GCC_REQD+=		2.95.3
.endif

PLIST_SUBST+=		DISTNAME=${EMACS_DISTNAME}
FILES_SUBST+=		DISTNAME=${EMACS_DISTNAME}
MESSAGE_SUBST+=		DISTNAME=${EMACS_DISTNAME}
INFO_FILES=	yes

.include "options.mk"

# The XEmacs configure script does something silly to the value of mandir
# passed to the configure script to point it to where the man1 pages go.
# Point it there directly.
#
GNU_CONFIGURE_MANDIR=	${PREFIX:Q}/${PKGMANDIR}/man1

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-clash-detection
CONFIGURE_ARGS+=	--with-mule
CONFIGURE_ARGS+=	--with-zlib
CONFIGURE_ARGS+=	--without-msw
CONFIGURE_ARGS+=	--with-pdump
CFLAGS+=		-Dunix

# Newer gcc has big trouble with aliasing.  This should be fixed in the
# source, but until then, use the big hammer here.
#
CFLAGS+=		-fno-strict-aliasing

.if ${X11_TYPE} != "modular"
INFOPATH=		${PREFIX}/${PKGINFODIR}:${X11BASE}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
.else
INFOPATH=		${PREFIX}/${PKGINFODIR}:${LOCALBASE}/${PKGINFODIR}
.endif
CONFIGURE_ARGS+=	--with-infopath=${INFOPATH:Q}

# Having the build path in the dumped emacs is not a problem.
CHECK_WRKREF_SKIP+=	bin/xemacs
CHECK_WRKREF_SKIP+=	bin/xemacs-${EMACSVERSION}

LIBDIR=			${PREFIX}/lib/${EMACS_DISTNAME}
ARCHLIBDIR=		${LIBDIR}/${MACHINE_GNU_PLATFORM}

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

pre-build:
	rm -f ${WRKSRC}/etc/ctags.1.orig

.include "../../databases/gdbm/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/termcap.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
