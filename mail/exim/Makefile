# $NetBSD: Makefile,v 1.40 2003/09/02 12:19:36 abs Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	1
CATEGORIES=	mail net

MAINTAINER=	ad@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

DEPENDS+=	exim-user>=4.10nb1:../../mail/exim-user
CONFLICTS+=	exim-exiscan-[0-9]*

.include "Makefile.common"

# Note: The distinfo in this directory includes the exiscan-acl-4.22-10.patch
# 'make mdi' or equivalent should be run from ../exim-exiscan-acl
