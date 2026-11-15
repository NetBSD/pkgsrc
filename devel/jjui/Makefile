# $NetBSD: Makefile,v 1.45 2026/11/15 20:06:08 wiz Exp $

DISTNAME=	jjui-0.10.13
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=idursun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/idursun/jjui/
COMMENT=	Text user interface for jj
LICENSE=	mit

DEPENDS+=	jj>=0.39:../../devel/jj

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
