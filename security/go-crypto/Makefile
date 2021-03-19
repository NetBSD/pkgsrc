# $NetBSD: Makefile,v 1.37 2021/03/19 17:37:04 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	7

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
