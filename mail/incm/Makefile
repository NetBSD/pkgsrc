# $NetBSD: Makefile,v 1.2 2003/06/02 01:18:45 jschauma Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.mew.org
COMMENT=	Tool to get mail from mbox file or maildir

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
