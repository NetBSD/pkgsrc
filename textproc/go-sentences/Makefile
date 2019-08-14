# $NetBSD: Makefile,v 1.14 2019/08/14 15:45:49 bsiegert Exp $

DISTNAME=	sentences-1.0.6
PKGNAME=	go-${DISTNAME}
PKGREVISION=	11
MASTER_SITES=	${MASTER_SITE_GITHUB:=neurosnap/}
CATEGORIES=	textproc
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT= ${PKGBASE:S/^go-//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/neurosnap/sentences
COMMENT=	Multilingual command line sentence tokenizer in Golang
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	gopkg.in/neurosnap/sentences.v1

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
