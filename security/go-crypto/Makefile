# $NetBSD: Makefile,v 1.39 2021/06/06 12:18:57 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	9

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
