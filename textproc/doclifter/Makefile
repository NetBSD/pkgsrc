# $NetBSD: Makefile,v 1.22 2010/02/10 19:17:46 joerg Exp $
#

DISTNAME=	doclifter-2.3
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://catb.org/~esr/doclifter/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://catb.org/~esr/doclifter/
COMMENT=	Translates documents written in troff macros to DocBook

NO_BUILD=	yes

PYTHON_PATCH_SCRIPTS=		doclifter manlifter

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		bin-path
SUBST_STAGE.bin-path=	pre-configure
SUBST_FILES.bin-path=	manlifter
SUBST_SED.bin-path=	-e 's,@@BIN_PATH@@,${PREFIX}/bin,g'

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/doclifter ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doclifter.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_SCRIPT} ${WRKSRC}/manlifter ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/manlifter.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
