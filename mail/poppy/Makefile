# $NetBSD: Makefile,v 1.2 2001/06/27 11:25:38 zuntum Exp $
#

DISTNAME=	poppy-3.1
CATEGORIES=	mail
MASTER_SITES=	http://home.sprynet.com/~cbagwell/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://home.sprynet.com/~cbagwell/projects.html
COMMENT=	client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	YES
USE_PERL5=	YES
REPLACE_PERL=	poppy

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
