# $NetBSD: Makefile,v 1.36 2021/01/23 14:23:10 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	6

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
