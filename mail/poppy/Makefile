# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:03 jlam Exp $
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

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
