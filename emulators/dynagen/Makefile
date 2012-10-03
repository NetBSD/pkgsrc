# $NetBSD: Makefile,v 1.5 2012/10/03 12:55:11 asau Exp $

DISTNAME=	dynagen-0.11.0
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=dyna-gen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dynagen.org/
COMMENT=	Network configuration generator for Dynamips
LICENSE=	gnu-gpl-v2

DEPENDS+=	dynamips>=0.2.8rc1:../../emulators/dynamips

NO_BUILD=	yes
PY_PATCHPLIST=	yes
REPLACE_PYTHON+= dynagen confConsole.py console.py dynamips_lib.py pemu_lib.py \
		pemubin.py pemuwrapper.py

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	post-patch
SUBST_FILES.paths=	dynagen
SUBST_SED.paths=	-e "s|@SYSCONFDIR@|${PKG_SYSCONFDIR}|"
SUBST_SED.paths+=	-e "s|@PREFIX@|${PREFIX}|"

CONF_FILES+=		share/examples/dynagen/dynagen.ini ${PKG_SYSCONFDIR}/dynagen.ini

INSTALLATION_DIRS=	bin ${PYSITELIB}/dynagen share/dynagen \
			share/doc/dynagen/tutorial_files share/examples/dynagen

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/dynagen ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/*.py* ${DESTDIR}${PREFIX}/${PYSITELIB}/dynagen
	${INSTALL_SCRIPT} ${FILESDIR}/*.py* ${DESTDIR}${PREFIX}/${PYSITELIB}/dynagen
	${INSTALL_DATA} ${WRKSRC}/configspec ${DESTDIR}${PREFIX}/share/dynagen
	${INSTALL_DATA} ${WRKSRC}/docs/*htm* ${DESTDIR}${PREFIX}/share/doc/dynagen
	${INSTALL_DATA} ${WRKSRC}/docs/tutorial_files/* \
		${DESTDIR}${PREFIX}/share/doc/dynagen/tutorial_files
	${INSTALL_DATA} ${WRKSRC}/dynagen.ini ${DESTDIR}${PREFIX}/share/examples/dynagen
	cp -R ${WRKSRC}/sample_labs/* ${DESTDIR}${PREFIX}/share/examples/dynagen

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
