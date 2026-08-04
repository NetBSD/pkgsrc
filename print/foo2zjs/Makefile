# $NetBSD: Makefile,v 1.7 2026/08/04 20:29:13 wiz Exp $

DISTNAME=	foo2zjs
PKGNAME=	${DISTNAME}-20120516
PKGREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	http://foo2zjs.rkkda.com/

MAINTAINER=	imil@NetBSD.org
#HOMEPAGE=	http://foo2zjs.rkkda.com/
COMMENT=	Printer driver for Zenographics ZjStream wire protocol
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake groff gsed:run

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1
INSTALLATION_DIRS+=	share/foo2zjs share/foomatic/ppd/foo2zjs

DEPENDS+=	foomatic-filters-cups>=3.0:../../print/foomatic-filters-cups

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Fix PREFIX.
SUBST_FILES.paths=	Makefile icc2ps/Makefile
SUBST_SED.paths=	-e "s,@PREFIX@,${DESTDIR}${PREFIX},"
SUBST_SED.paths+=	-e "s,@PKGMANDIR@,${DESTDIR}${PREFIX}/${PKGMANDIR},"
SUBST_SED.paths+=	-e "s,@RUNPREFIX@,${PREFIX},"
SUBST_STAGE.paths=	pre-configure

do-build:
	cd ${WRKSRC} && ${GMAKE} ${PROGS}

do-install:
	cd ${WRKSRC} && ${GMAKE} install-prog install-man install-crd
	# cheaper than upstream's "portable" Makefile
	${INSTALL_DATA} ${WRKSRC}/PPD/*.ppd	\
		${DESTDIR}${PREFIX}/share/foomatic/ppd/foo2zjs

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../mk/bsd.pkg.mk"
