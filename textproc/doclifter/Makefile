# $NetBSD: Makefile,v 1.9 2004/12/25 15:59:17 wiz Exp $
#

DISTNAME=	doclifter-2.0
CATEGORIES=	textproc
MASTER_SITES=	http://catb.org/~esr/doclifter/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook

NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=		doclifter manlifter
PYTHON_VERSIONS_ACCEPTED=	24pth 24 23pth 23 22pth 22

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${PREFIX}/man/man1
# Not yet (only works when run as "./manlifter"
#	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${PREFIX}/bin
#	${INSTALL_MAN} ${WRKSRC}/manlifter.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
