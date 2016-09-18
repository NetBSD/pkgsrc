# $NetBSD: Makefile,v 1.4 2016/09/18 23:13:13 wiedi Exp $

DISTNAME=	radsecproxy-1.6.6
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	https://software.uninett.no/radsecproxy/

MAINTAINER=	he@NetBSD.org
COMMENT=	Secure radius proxy
HOMEPAGE=	https://software.uninett.no/radsecproxy/
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
