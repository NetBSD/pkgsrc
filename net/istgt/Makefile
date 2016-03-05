# $NetBSD: Makefile,v 1.15 2016/03/05 11:29:05 jperkin Exp $
#

DISTNAME=		istgt-20141125
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		http://www.peach.ne.jp/archives/istgt/

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://shell.peach.ne.jp/aoyama/
COMMENT=		Configurable iSCSI target
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	istgt

CONFIGURE_ARGS+=	--with-configdir=${PKG_SYSCONFDIR}

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fixing hardcoded paths.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	doc/istgt.1.in src/istgt.h src/istgtcontrol.c
SUBST_SED.paths=	-e "s,/usr/local,${PREFIX},"

EG_DIR=		${PREFIX}/share/examples/istgt
CONF_FILES=	${EG_DIR}/auth.conf ${PKG_SYSCONFDIR}/auth.conf \
		${EG_DIR}/istgt.conf ${PKG_SYSCONFDIR}/istgt.conf \
		${EG_DIR}/istgtcontrol.conf ${PKG_SYSCONFDIR}/istgtcontrol.conf

RCD_SCRIPTS=	istgt
INSTALLATION_DIRS+=	bin ${EG_DIR} ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/istgt ${DESTDIR}${PREFIX}/bin/istgt
	${INSTALL_PROGRAM} ${WRKSRC}/src/istgtcontrol \
		${DESTDIR}${PREFIX}/bin/istgtcontrol
	${INSTALL_DATA} ${WRKSRC}/etc/auth.conf ${DESTDIR}${EG_DIR}/auth.conf
	${INSTALL_DATA} ${WRKSRC}/etc/istgt.conf ${DESTDIR}${EG_DIR}/istgt.conf
	${INSTALL_DATA} ${WRKSRC}/etc/istgt.large.conf \
		${DESTDIR}${EG_DIR}/istgt.large.conf
	${INSTALL_DATA} ${WRKSRC}/etc/istgtcontrol.conf \
		${DESTDIR}${EG_DIR}/istgtcontrol.conf
	${INSTALL_MAN} ${WRKSRC}/doc/istgt.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/istgt.1

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
