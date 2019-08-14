# $NetBSD: Makefile,v 1.14 2019/08/14 15:45:44 bsiegert Exp $

DISTNAME=	stats-0.2.0.20170729
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=montanaflynn/}
CATEGORIES=	math
GITHUB_TAG=	4a163274fa4ca0b524ccee24757d7bec79475aca
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/montanaflynn/stats
COMMENT=	Statistics package to supplement the Golang standard library
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/montanaflynn/stats

# Avoid build issues with the examples
post-patch:
	${RUN} ${RM} -rf ${WRKSRC}/examples

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
