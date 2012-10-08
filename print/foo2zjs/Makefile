# $NetBSD: Makefile,v 1.2 2012/10/08 13:45:38 asau Exp $
#

DISTNAME=	foo2zjs
PKGNAME=	${DISTNAME}-20120516
CATEGORIES=	print
MASTER_SITES=	http://foo2zjs.rkkda.com/

MAINTAINER=	imil@NetBSD.org
HOMEPAGE=	http://foo2zjs.rkkda.com/
COMMENT=	Printer driver for Zenographics ZjStream wire protocol
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/foo2zjs share/foomatic/ppd/foo2zjs

DEPENDS+=	foomatic-filters-cups>=3.0:../../print/foomatic-filters-cups

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fix PREFIX.
SUBST_FILES.paths=	Makefile icc2ps/Makefile
SUBST_SED.paths=	-e "s,@PREFIX@,${DESTDIR}${PREFIX},"
SUBST_SED.paths+=	-e "s,@PKGMANDIR@,${DESTDIR}${PREFIX}/${PKGMANDIR},"
SUBST_STAGE.paths=	post-patch

do-build:
	cd ${WRKSRC} && ${GMAKE} ${PROGS}

do-install:
	cd ${WRKSRC} && ${GMAKE} install-prog install-man
	# cheaper than upstream's "portable" Makefile
	${INSTALL_DATA} ${WRKSRC}/PPD/*.ppd	\
		${DESTDIR}${PREFIX}/share/foomatic/ppd/foo2zjs

.include "../../mk/bsd.pkg.mk"
