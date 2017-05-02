# $NetBSD: Makefile,v 1.11 2017/05/02 17:06:30 fhajny Exp $

#PKGREVISION=	#

COMMENT=	Go supplementary cryptography libraries

GO_SRCPATH=	golang.org/x/crypto
GO_DIST_BASE=	${GITHUB_PROJECT}-${GITHUB_TAG}*

# The "acme" package depends on x/net/context.
pre-patch:
	${RM} -r ${WRKSRC}/acme

.include "Makefile.common"
