# $NetBSD: Makefile,v 1.1.1.1 2004/12/28 15:51:16 xtraeme Exp $
#

DISTNAME=	pfqueue-0.1.4
CATEGORIES=	mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pfqueue/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://pfqueue.sourceforge.net/
COMMENT=	Real-time queue scanner for postfix

USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/pfqueue ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/pfqueue.1 ${PREFIX}/man/man1

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
