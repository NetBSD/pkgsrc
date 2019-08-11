# $NetBSD: Makefile,v 1.20 2019/08/11 13:21:40 wiz Exp $
#

DISTNAME=	poppy-4.01
#KGREVISION=	1
PKGREVISION=	6
CATEGORIES=	mail
MASTER_SITES=	http://www.cnpbagwell.com/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.cnpbagwell.com/projects.html
COMMENT=	Client to perform simple tasks with a POP3/IMAP server

NO_BUILD=	YES
USE_TOOLS+=	perl:run
REPLACE_PERL=	poppy

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/poppy ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/poppy.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
