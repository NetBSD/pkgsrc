# $NetBSD: Makefile,v 1.3 2019/10/18 14:58:52 bsiegert Exp $
#

NAME=			iochan
VERSION=		1.0.0
DISTNAME=		${NAME}-${VERSION}
PKGNAME=		go-${DISTNAME}
PKGREVISION=		2
GITHUB_PROJECT=		${NAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mitchellh/}
GITHUB_TAG=		v${VERSION}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mitchellh/iochan
COMMENT=		Go library for treating io r/w like channels
LICENSE=		mit

GO_SRCPATH=		github.com/mitchellh/iochan
GO_DIST_BASE=		${DISTNAME}*

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
