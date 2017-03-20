# $NetBSD: Makefile,v 1.9 2017/03/20 22:53:45 bsiegert Exp $

PKGREVISION=	1

COMMENT=	Go supplementary cryptography libraries

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

# The "acme" package depends on x/net/context.
pre-patch:
	${RM} -r ${WRKSRC}/acme

.include "Makefile.common"
