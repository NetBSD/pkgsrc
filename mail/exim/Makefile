# $NetBSD: Makefile,v 1.44.2.1 2004/05/30 08:54:13 grant Exp $

DISTNAME=	exim-${EXIM_VERSION}
PKGREVISION=	5
CATEGORIES=	mail net

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.exim.org/
COMMENT=	The Exim mail transfer agent, a replacement for sendmail

DEPENDS+=	exim-user>=4.10nb1:../../mail/exim-user
CONFLICTS+=	exim-exiscan-[0-9]*

.include "Makefile.common"

# Note: The distinfo in this directory includes the exiscan-acl-4.22-10.patch
# 'make mdi' or equivalent should be run from ../exim-exiscan-acl
