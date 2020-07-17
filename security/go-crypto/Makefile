# $NetBSD: Makefile,v 1.34 2020/07/17 18:04:27 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	4

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
