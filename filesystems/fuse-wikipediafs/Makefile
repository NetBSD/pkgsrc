# $NetBSD: Makefile,v 1.1.1.1 2007/08/09 21:42:52 agc Exp $
#

DISTNAME=	wikipediafs-0.3
PKGNAME=	fuse-${DISTNAME}
CATEGORIES=	filesystems
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wikipediafs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wikipediafs.sourceforge.net/
COMMENT=	FUSE filesystem for acecssing the wikipedia

NO_BUILD=	yes
PYTHON_VERSIONS_ACCEPTED=	24

PLIST_SUBST+=		PYSITELIB=${PYSITELIB:Q}

SUBST_CLASSES+=		config
SUBST_STAGE.config=	post-patch
SUBST_FILES.config=	setup.py
SUBST_SED.config+=	-e "s|@PREFIX@|${PREFIX}|g"
SUBST_SED.config+=	-e "s|@PKGMANDIR@|${PKGMANDIR}|g"
SUBST_SED.config+=	-e "s|@PYSITELIB@|${PREFIX}/${PYSITELIB}|g"
SUBST_MESSAGE.config=   Fixing paths.

do-build:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py build

do-install:
	cd ${WRKSRC} && ${PYTHONBIN} setup.py install

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
PRIVILEGED_STAGES+=	clean
.endif

.include "../../filesystems/py-fuse-bindings/buildlink3.mk"

.include "../../lang/python/application.mk"
.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
