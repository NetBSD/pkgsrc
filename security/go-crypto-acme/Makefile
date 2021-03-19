# $NetBSD: Makefile,v 1.11 2021/03/19 17:37:04 bsiegert Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
PKGREVISION=	4
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

CHECK_RELRO_SKIP+=	bin/acmeprobe

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"
