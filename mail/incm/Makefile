# $NetBSD: Makefile,v 1.3 2003/07/17 21:46:19 grant Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mew.org
COMMENT=	Tool to get mail from mbox file or maildir

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
