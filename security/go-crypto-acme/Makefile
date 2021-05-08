# $NetBSD: Makefile,v 1.12 2021/05/08 15:02:29 bsiegert Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
PKGREVISION=	5
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

CHECK_RELRO_SKIP+=	bin/acmeprobe

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"
