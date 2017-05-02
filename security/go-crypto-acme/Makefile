# $NetBSD: Makefile,v 1.3 2017/05/02 17:06:30 fhajny Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"

