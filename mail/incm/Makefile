# $NetBSD: Makefile,v 1.1.1.1 2002/07/08 15:27:00 yyamano Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.mew.org
COMMENT=	Tool to get mail from mbox file or maildir

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
