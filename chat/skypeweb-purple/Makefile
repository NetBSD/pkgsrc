# $NetBSD: Makefile,v 1.18 2023/11/08 13:18:17 wiz Exp $

VERSION=	1.7
DISTNAME=	skype4pidgin-${VERSION}
PKGNAME=	skypeweb-purple-${VERSION}
PKGREVISION=	6
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GITHUB:=EionRobb/}
# default picks from PKGNAME
GITHUB_PROJECT=	skype4pidgin

HOMEPAGE=	https://github.com/EionRobb/skype4pidgin/tree/master/skypeweb
COMMENT=	Skype (HTTP) plugin for libpurple messengers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gmake pkg-config

WRKSRC=		${WRKDIR}/${DISTNAME}/skypeweb

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../chat/libpurple/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
