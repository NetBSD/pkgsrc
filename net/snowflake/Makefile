# $NetBSD: Makefile,v 1.4 2024/06/01 14:02:57 bsiegert Exp $

DISTNAME=	snowflake-v2.8.1
PKGNAME=	${DISTNAME:S,-v,-,}
PKGREVISION=	3
CATEGORIES=	net security
MASTER_SITES=	https://gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/snowflake/-/archive/v${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.torproject.org/tpo/anti-censorship/pluggable-transports/snowflake
COMMENT=	Pluggable Transport for tor using WebRTC, inspired by Flashproxy
LICENSE=	modified-bsd

USE_LANGUAGES=	c

INSTALLATION_DIRS+=	share/doc/snowflake

post-install:
.for file in broker client probetest proxy server
	cd ${DESTDIR}${PREFIX}/bin && ${MV} ${file} snowflake-${file}
.endfor
	${INSTALL_DATA} ${WRKSRC}/README.md ${DESTDIR}${PREFIX}/share/doc/snowflake

.include "go-module.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
