# $NetBSD: Makefile,v 1.1 2016/08/20 09:33:53 bsiegert Exp $
#

DISTNAME=		lf-20160819
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_GITHUB:=gokcehan/}
GITHUB_PROJECT=		lf
GITHUB_TAG=		a6d92f4

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Pure Go termbox implementation
LICENSE=		2-clause-bsd

GO_SRCPATH=		github.com/gokcehan/lf
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../devel/go-termbox/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
