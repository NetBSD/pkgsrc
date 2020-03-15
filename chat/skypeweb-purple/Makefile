# $NetBSD: Makefile,v 1.5 2020/03/15 11:53:22 mef Exp $

DISTNAME=	skype4pidgin-1.3
PKGNAME=	skypeweb-purple-1.3
PKGREVISION=	2
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
