# $NetBSD: Makefile,v 1.14 2025/12/08 10:06:24 wiz Exp $

DISTNAME=	jjui-0.9.7
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=idursun/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/idursun/jjui/
COMMENT=	Text user interface for jj
LICENSE=	mit

DEPENDS+=	jj>=0.21:../../devel/jj

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
