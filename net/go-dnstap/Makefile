# $NetBSD: Makefile,v 1.14 2020/03/21 16:57:05 bsiegert Exp $

DISTNAME=		go-dnstap-0.1.0
PKGREVISION=		12
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=dnstap/}
GITHUB_PROJECT=		golang-dnstap
GITHUB_TAG=		tags/v${PKGVERSION_NOREV}
GITHUB_TYPE=		tag

HOMEPAGE=		https://${GO_SRCPATH}
COMMENT=		Go language implementation of framestream protocol
LICENSE=		apache-2.0

GO_SRCPATH=		github.com/dnstap/golang-dnstap
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG:S!/!-!}

.include "../../lang/go/go-package.mk"
.include "../../net/go-framestream/buildlink3.mk"
.include "../../net/go-dns/buildlink3.mk"
.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
