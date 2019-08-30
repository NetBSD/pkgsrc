# $NetBSD: Makefile,v 1.2 2019/08/30 19:22:58 maya Exp $
#

NAME=			gox
DISTNAME=		${NAME}-1.0.1
PKGNAME=		go-${DISTNAME}
GITHUB_PROJECT=		${NAME}
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GITHUB:=mitchellh/}
GITHUB_TAG=		v1.0.1

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://github.com/mitchellh/gox
COMMENT=		Tool for go cross compilation
LICENSE=		mpl-2.0

GO_SRCPATH=		github.com/mitchellh/gox
GO_DIST_BASE=		${DISTNAME}*

#DEPENDS+=		go-iochan-[0-9]*:../../devel/go-iochan

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
