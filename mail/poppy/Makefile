# $NetBSD: Makefile,v 1.7 2005/07/16 01:19:13 jlam Exp $
#

DISTNAME=	poppy-3.1
CATEGORIES=	mail
MASTER_SITES=	http://www.cnpbagwell.com/

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.cnpbagwell.com/projects.html
COMMENT=	Client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	poppy

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
