# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	incm-0.5
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.mew.org/pub/Mew/release/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.mew.org/
COMMENT=	Tool to get mail from mbox file or maildir

CONFLICTS=	mew-[0-9]*

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/incm ${PREFIX}/bin/

.include "../../mk/bsd.pkg.mk"
