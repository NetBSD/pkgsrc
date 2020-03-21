# $NetBSD: Makefile,v 1.8 2020/03/21 16:57:04 bsiegert Exp $

PKGNAME=	${DISTNAME:S/crypto/crypto-acme/}
PKGREVISION=	1
COMMENT=	ACME library from go-crypto

GO_SRCPATH=	golang.org/x/crypto/acme
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*/acme

CHECK_RELRO_SKIP+=	bin/acmeprobe

.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-crypto/Makefile.common"
