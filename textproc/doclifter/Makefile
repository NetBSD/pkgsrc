# $NetBSD: Makefile,v 1.1.1.1 2004/01/17 01:07:14 recht Exp $
#

DISTNAME=	doclifter-1.6
CATEGORIES=	textproc
MASTER_SITES=	http://catb.org/~esr/doclifter/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook

NO_BUILD=	yes
USE_BUILDLINK2=	yes

PYTHON_PATCH_SCRIPTS=		doclifter
PYTHON_VERSIONS_ACCEPTED=	23pth 23 22pth 22

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
