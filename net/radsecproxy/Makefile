# $NetBSD: Makefile,v 1.5 2017/08/03 11:30:45 he Exp $

DISTNAME=	radsecproxy-1.6.9
CATEGORIES=	net
MASTER_SITES=	https://software.nordu.net/radsecproxy/

MAINTAINER=	he@NetBSD.org
COMMENT=	Secure radius proxy
HOMEPAGE=	https://software.nordu.net/radsecproxy/download/
EXTRACT_SUFX=	.tar.xz
LICENSE=	gnu-gpl-v2 OR modified-bsd

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR:Q}
CONFIGURE_ARGS+=	--with-ssl=${BUILDLINK_PREFIX.openssl}

EGDIR=		${PREFIX}/share/examples/radsecproxy
INSTALLATION_DIRS+=	${EGDIR}

CONF=		radsecproxy.conf
CONF_FILES+=	${EGDIR}/${CONF} ${PKG_SYSCONFDIR}/${CONF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${DESTDIR}${EGDIR}/${CONF}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
