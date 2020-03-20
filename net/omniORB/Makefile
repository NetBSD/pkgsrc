# $NetBSD: Makefile,v 1.23 2020/03/20 11:58:09 nia Exp $

DISTNAME=		omniORB-4.1.7
PKGREVISION=		2
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=omniorb/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		ianzag@mail.ru
HOMEPAGE=		http://omniorb.sourceforge.net/
COMMENT=		CORBA ORB

MAKE_FILE=		GNUmakefile

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++03
USE_TOOLS+=	gmake

PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omniCOS4.pc.in
PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omniCOSDynamic4.pc.in
PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omniConnectionMgmt4.pc.in
PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omniDynamic4.pc.in
PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omniORB4.pc.in
PKGCONFIG_OVERRIDE+=	contrib/pkgconfig/omnithread3.pc.in

# omniORB requires native threads support
PTHREAD_OPTS=	require native
RCD_SCRIPTS=	omninames

OMNIORB_ETCDIR?=	${PKG_SYSCONFDIR}
OMNIORB_CONFIG=		${OMNIORB_ETCDIR}/omniORB.cfg

CONFIGURE_ARGS+=	--with-omniORB-config=${OMNIORB_CONFIG:Q}
#CONFIGURE_ARGS+=	--with-omniNames-logdir=
#CONFIGURE_ARGS+=	--with-openssl

PKG_OPTIONS_VAR=	PKG_OPTIONS.omniORB
PKG_SUPPORTED_OPTIONS=	inet6
PKG_SUGGESTED_OPTIONS=	inet6

.include "../../mk/bsd.options.mk"
.if empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=--disable-ipv6
.endif

PY_PATCHPLIST=			yes
REPLACE_PYTHON+=		src/tool/omniidl/python/scripts/omniidlrun.py
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 4.1.7

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
