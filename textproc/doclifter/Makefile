# $NetBSD: Makefile,v 1.11 2005/01/23 20:41:49 recht Exp $
#

DISTNAME=	doclifter-2.0
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	http://catb.org/~esr/doclifter/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook

NO_BUILD=	yes
USE_BUILDLINK3=	yes

PYTHON_PATCH_SCRIPTS=		doclifter manlifter
PYTHON_VERSIONS_ACCEPTED=	24 23 22

SUBST_CLASSES+=		bin-path
SUBST_STAGE.bin-path=	pre-configure
SUBST_FILES.bin-path=	manlifter
SUBST_SED.bin-path=	-e 's,@@BIN_PATH@@,${PREFIX}/bin,g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 ${PREFIX}/man/man1
	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/manlifter.1 ${PREFIX}/man/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
