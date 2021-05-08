# $NetBSD: Makefile,v 1.38 2021/05/08 15:02:29 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	8

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
