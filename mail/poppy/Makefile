# $NetBSD: Makefile,v 1.5 2004/07/23 14:28:56 zuntum Exp $
#

DISTNAME=	poppy-3.1
CATEGORIES=	mail
MASTER_SITES=	http://www.cnpbagwell.com/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.cnpbagwell.com/projects.html
COMMENT=	Client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	YES
USE_PERL5=	YES
REPLACE_PERL=	poppy

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
