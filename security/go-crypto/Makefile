# $NetBSD: Makefile,v 1.35 2020/11/13 19:26:20 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	5

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
