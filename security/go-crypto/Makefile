# $NetBSD: Makefile,v 1.10 2017/04/13 15:12:06 bsiegert Exp $

PKGREVISION=	2

COMMENT=	Go supplementary cryptography libraries

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

# The "acme" package depends on x/net/context.
pre-patch:
	${RM} -r ${WRKSRC}/acme

.include "Makefile.common"
