# $NetBSD: Makefile,v 1.6 2017/04/13 15:12:05 bsiegert Exp $

DISTNAME=	go-vultr-1.8
PKGREVISION=	5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=JamesClonk/}
GITHUB_PROJECT=	vultr
GITHUB_TAG=	v1.8

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://jamesclonk.github.io/vultr/
COMMENT=	Vultr CLI and API client library
LICENSE=	mit

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_SRCPATH=	github.com/JamesClonk/vultr

post-patch:
	${RM} -rf ${WRKSRC}/Godeps

.include "../../devel/go-mow-cli/buildlink3.mk"
.include "../../devel/go-ratelimit/buildlink3.mk"
.include "../../devel/go-testify/buildlink3.mk"
.include "../../security/go-crypto/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
