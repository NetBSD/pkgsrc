# $NetBSD: Makefile,v 1.6 2004/08/15 11:26:31 wiz Exp $
#

DISTNAME=	doclifter-1.13
CATEGORIES=	textproc
MASTER_SITES=	http://catb.org/~esr/doclifter/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook

NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=		doclifter
PYTHON_VERSIONS_ACCEPTED=	23pth 23 22pth 22

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
