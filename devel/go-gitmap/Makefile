# $NetBSD: Makefile,v 1.1 2017/08/17 01:26:34 gavan Exp $

DISTNAME=	gitmap-0.0.20170613
PKGNAME=	go-${DISTNAME}
MASTER_SITES=	${MASTER_SITE_GITHUB:=bep/}
CATEGORIES=	devel
GITHUB_TAG=	de8030ebafb76c6e84d50ee6d143382637c00598
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/bep/gitmap/
COMMENT=	A fairly fast way to create a map from all the filenames to info objects for a given revision of a Git repo.
LICENSE=	mit

GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/bep/gitmap

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"

