# $NetBSD: Makefile,v 1.40 2021/07/13 11:36:34 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	10

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
