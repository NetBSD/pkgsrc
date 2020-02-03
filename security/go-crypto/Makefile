# $NetBSD: Makefile,v 1.30 2020/02/03 14:51:55 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

pre-patch:
	${RM} -rf ${WRKSRC}/acme

.include "Makefile.common"
