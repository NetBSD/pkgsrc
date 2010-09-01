# $NetBSD: Makefile,v 1.1.1.1 2010/09/01 15:52:58 drochner Exp $
#

DISTNAME=		omniORB-4.1.4
CATEGORIES=		devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=omniorb/}

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://omniorb.sourceforge.net/
COMMENT=		CORBA ORB

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_FILE=		GNUmakefile
GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omniCOS4.pc.in
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omniCOSDynamic4.pc.in
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omniConnectionMgmt4.pc.in
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omniDynamic4.pc.in
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omniORB4.pc.in
PKGCONFIG_OVERRIDE+= contrib/pkgconfig/omnithread3.pc.in

# Note: not sure if it is required though
USE_LIBTOOL=	YES

# omniORB requires native threads support
PTHREAD_OPTS=	require native
RCD_SCRIPTS= 	omninames

OMNIORB_ETCDIR?= ${PKG_SYSCONFDIR}
OMNIORB_CONFIG=	${OMNIORB_ETCDIR}/omniORB.cfg

CONFIGURE_ENV+=  PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+= --with-omniORB-config=${OMNIORB_CONFIG:Q}
#CONFIGURE_ARGS+= --with-omniNames-logdir=
#CONFIGURE_ARGS+= --with-openssl

PKG_OPTIONS_VAR=	PKG_OPTIONS.omniORB
PKG_SUPPORTED_OPTIONS=	inet6
.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

PY_PATCHPLIST=	yes
REPLACE_PYTHON+= src/tool/omniidl/python/scripts/omniidlrun.py

pre-install:
	cd ${WRKSRC}/include && ${SETENV} ${MAKE_ENV} ${GMAKE} install

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/omniORB/omniORB
	${INSTALL_DATA} ${WRKSRC}/sample.cfg \
		${DESTDIR}${PREFIX}/share/examples/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.html \
		${DESTDIR}${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/*.pdf \
		${DESTDIR}${PREFIX}/share/doc/omniORB/
	${INSTALL_DATA} ${WRKSRC}/doc/omniORB/* \
		${DESTDIR}${PREFIX}/share/doc/omniORB/omniORB/
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/
	${INSTALL_MAN} ${WRKSRC}/man/man1/* \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
