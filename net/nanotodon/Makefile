# $NetBSD: Makefile,v 1.1 2020/02/08 00:53:01 tsutsui Exp $

GITHUB_TAG=	v0.1.0
DISTNAME=	nanotodon-${GITHUB_TAG:S/v//}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=taka-tuos/}

MAINTAINER=	tsutsui@NetBSD.org
HOMEPAGE=	https://github.com/taka-tuos/nanotodon
COMMENT=	CUI/C99 mastodon client
LICENSE=	mit

INSTALLATION_DIRS+=	bin

BUILD_TARGET=	default

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/nanotodon ${DESTDIR}${PREFIX}/bin

.include "../../devel/ncursesw/buildlink3.mk"
.include "../../textproc/json-c/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
