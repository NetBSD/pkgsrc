# $NetBSD: Makefile,v 1.32 2020/04/12 11:01:45 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	2

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
