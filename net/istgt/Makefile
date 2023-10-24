# $NetBSD: Makefile,v 1.22 2023/10/24 22:10:19 wiz Exp $
#

DISTNAME=		istgt-20150713
PKGREVISION=		2
CATEGORIES=		net
MASTER_SITES=		http://www.peach.ne.jp/archives/istgt/

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		https://github.com/elastocloud/istgt
COMMENT=		Configurable iSCSI target
LICENSE=		modified-bsd

GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	istgt

CONFIGURE_ARGS+=	--with-configdir=${PKG_SYSCONFDIR}

EG_DIR=		${PREFIX}/share/examples/istgt
CONF_FILES=	${EG_DIR}/auth.conf ${PKG_SYSCONFDIR}/auth.conf \
		${EG_DIR}/istgt.conf ${PKG_SYSCONFDIR}/istgt.conf \
		${EG_DIR}/istgtcontrol.conf ${PKG_SYSCONFDIR}/istgtcontrol.conf

RCD_SCRIPTS=		istgt
INSTALLATION_DIRS+=	bin ${EG_DIR} ${PKGMANDIR}/man1

CPPFLAGS.SunOS+=	-D_POSIX_PTHREAD_SEMANTICS
LDFLAGS.SunOS+=		-lsocket -lnsl -fstack-protector

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
