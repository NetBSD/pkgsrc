# $NetBSD: Makefile,v 1.14 2019/08/14 15:45:37 bsiegert Exp $

DISTNAME=	gitmap-0.0.20170613
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=bep/}
CATEGORIES=	devel
GITHUB_TAG=	de8030ebafb76c6e84d50ee6d143382637c00598
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bep/gitmap/
COMMENT=	Git repository object map creator
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/bep/gitmap

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
