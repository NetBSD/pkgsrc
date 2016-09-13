# $NetBSD: Makefile,v 1.1 2016/09/13 20:42:12 bsiegert Exp $
#

DISTNAME=		go-genproto-20160816
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=		go-genproto
GITHUB_TAG=		44808ed

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Go generated proto packages
LICENSE=		apache-2.0

GO_SRCPATH=		google.golang.org/genproto
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-grpc/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
