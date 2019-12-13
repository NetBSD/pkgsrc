# $NetBSD: Makefile,v 1.21 2019/12/13 07:44:03 bsiegert Exp $
#

DISTNAME=		lf-20180302
PKGREVISION=		13
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_TAG=		c3f4aa5

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Terminal file manager
LICENSE=		2-clause-bsd

GO_SRCPATH=		github.com/gokcehan/lf
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../devel/go-termbox/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
