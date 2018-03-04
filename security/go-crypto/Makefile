# $NetBSD: Makefile,v 1.12 2018/03/04 15:52:18 bsiegert Exp $

COMMENT=	Go supplementary cryptography libraries
PKGREVISION=	1

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

# The "acme" package depends on x/net/context.
pre-patch:
	${RM} -r ${WRKSRC}/acme

.include "Makefile.common"
