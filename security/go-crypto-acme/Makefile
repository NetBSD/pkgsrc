# $NetBSD: Makefile,v 1.4 2017/08/25 16:49:14 jperkin Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"
