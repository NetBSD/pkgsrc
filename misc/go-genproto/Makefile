# $NetBSD: Makefile,v 1.3 2016/10/29 08:59:48 bsiegert Exp $

DISTNAME=		go-genproto-20160816
PKGREVISION=		2
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=google/}
GITHUB_PROJECT=		go-genproto
GITHUB_TAG=		44808ed

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Go generated proto packages
LICENSE=		apache-2.0

GO_SRCPATH=		google.golang.org/genproto
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG}*

REPLACE_SH+=		regen.sh

EXTRACT_USING=		bsdtar
USE_TOOLS+=		bsdtar

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-grpc/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
