# $NetBSD: Makefile,v 1.4 2003/07/21 16:56:53 martti Exp $
#

DISTNAME=	poppy-3.1
CATEGORIES=	mail
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://home.sprynet.com/~cbagwell/projects.html
COMMENT=	Client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	YES
USE_PERL5=	YES
REPLACE_PERL=	poppy

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
