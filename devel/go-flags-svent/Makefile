# $NetBSD: Makefile,v 1.31 2020/11/08 21:59:14 bsiegert Exp $

DISTNAME=	go-flags-svent-0.0.20141123
PKGREVISION=	30
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=svent/}
GITHUB_PROJECT=	go-flags
GITHUB_TAG=	4bcbad344f0318adaf7aabc16929701459009aa3

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/svent/go-flags/
COMMENT=	Go command line option parser (svent fork)
LICENSE=	modified-bsd

WRKSRC=		${WRKDIR}
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}
GO_SRCPATH=	github.com/svent/go-flags

REPLACE_SH=	check_crosscompile.sh

pre-configure:
	${RM} -rf ${WRKSRC}/examples

.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
