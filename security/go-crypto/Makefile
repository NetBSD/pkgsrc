# $NetBSD: Makefile,v 1.33 2020/06/17 09:54:15 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	3

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
