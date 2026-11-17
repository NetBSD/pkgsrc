# $NetBSD: Makefile,v 1.22 2026/11/17 09:40:39 adam Exp $

DISTNAME=	radsecproxy-1.11.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=radsecproxy/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://radsecproxy.github.io/
COMMENT=	Generic RADIUS proxy with RadSec support
LICENSE=	modified-bsd

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-openssl=${BUILDLINK_PREFIX.openssl}
TEST_TARGET=		check

EGDIR=			${PREFIX}/share/examples/radsecproxy
INSTALLATION_DIRS+=	${EGDIR}

CONF=		radsecproxy.conf
CONF_FILES+=	${EGDIR}/${CONF} ${PKG_SYSCONFDIR}/${CONF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${DESTDIR}${EGDIR}/${CONF}

.include "../../security/nettle/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
