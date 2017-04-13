# $NetBSD: Makefile,v 1.2 2017/04/13 15:12:06 bsiegert Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
PKGREVISION=	1
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"

