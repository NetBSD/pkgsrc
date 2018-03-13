# $NetBSD: Makefile,v 1.6 2018/03/13 17:32:57 bsiegert Exp $

DISTNAME=	go-md2man-1.0.6
MASTER_SITES=	${MASTER_SITE_GITHUB:=cpuguy83/}
PKGREVISION=	2
CATEGORIES=	textproc
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/cpuguy83/go-md2man/
COMMENT=	Uses blackfriday to process markdown into man pages
LICENSE=	mit

GO_DIST_BASE=	${DISTNAME}
GO_SRCPATH=	github.com/cpuguy83/go-md2man

post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/gopkg/pkg/${GO_PLATFORM}/${GO_SRCPATH}/vendor

.include "../../devel/go-blackfriday/buildlink3.mk"
.include "../../devel/go-sanitized_anchor_name/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
