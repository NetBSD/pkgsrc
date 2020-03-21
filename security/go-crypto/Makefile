# $NetBSD: Makefile,v 1.31 2020/03/21 16:57:04 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	1

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
