# $NetBSD: Makefile,v 1.3 2016/03/05 11:29:11 jperkin Exp $

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
CONFIGURE_ARGS+=        --sysconfdir=${PKG_SYSCONFBASEDIR:Q}

EGDIR=		${PREFIX}/share/examples/radsecproxy
INSTALLATION_DIRS+=	${EGDIR}

CONF=		radsecproxy.conf
CONF_FILES+=	${EGDIR}/${CONF} ${PKG_SYSCONFDIR}/${CONF}

post-install:
	${INSTALL_DATA} ${WRKSRC}/radsecproxy.conf-example \
		${DESTDIR}${EGDIR}/${CONF}

.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
