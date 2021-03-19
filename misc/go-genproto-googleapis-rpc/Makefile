# $NetBSD: Makefile,v 1.25 2021/03/19 17:37:00 bsiegert Exp $

PKGNAME=	${DISTNAME:S/genproto-/genproto-googleapis-rpc-/}
PKGREVISION=	24

COMMENT=	Generated Go packages for RPC

CONFLICTS=	go-genproto<=20160816nb7

.include "../../misc/go-genproto/Makefile.common"

EXTRACT_ELEMENTS=	${GITHUB_PROJECT}-${GITHUB_TAG}/googleapis/rpc

#GO_SRCPATH=	google.golang.org/genproto
#GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

GO_BUILD_PATTERN=	${GO_SRCPATH}/googleapis/rpc/...

.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
