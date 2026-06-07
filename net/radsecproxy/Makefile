# $NetBSD: Makefile,v 1.19 2026/06/07 17:45:46 adam Exp $

VERSION=	1.11.2
DISTNAME=	radsecproxy-${VERSION}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=radsecproxy/}
GITHUB_RELEASE=	${VERSION}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://radsecproxy.github.io/
COMMENT=	Secure radius proxy
LICENSE=	modified-bsd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
TEST_TARGET=		check

EGDIR=		${PREFIX}/share/examples/radsecproxy
INSTALLATION_DIRS+=	${EGDIR}

CONF=		radsecproxy.conf
CONF_FILES+=	${EGDIR}/${CONF} ${PKG_SYSCONFDIR}/${CONF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${DESTDIR}${EGDIR}/${CONF}

.include "../../security/openssl/buildlink3.mk"
.include "../../security/nettle/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
