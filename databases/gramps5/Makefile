# $NetBSD: Makefile,v 1.6 2021/12/30 13:05:29 adam Exp $

DISTNAME=		gramps-5.1.2
PKGREVISION=		3
CATEGORIES=		databases
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gramps/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gramps-project.org/
COMMENT=		Genealogical Research and Analysis Management Programming System V5
LICENSE=		gnu-gpl-v2

USE_TOOLS+=		msgfmt pkg-config intltool msgconv

PYTHON_VERSIONS_INCOMPATIBLE=	27

REPLACE_PYTHON+=	gramps/gen/utils/place.py
REPLACE_PYTHON+=	gramps/gen/datehandler/_date_fr.py
REPLACE_PYTHON+=	docs/update_doc.py
REPLACE_PYTHON+=	docs/conf.py
REPLACE_PYTHON+=	setup.py

SUBST_CLASSES+=		man
SUBST_FILES.man+=	setup.py
SUBST_STAGE.man+=	pre-configure
SUBST_MESSAGE.man+=	Fixing man page installation path
SUBST_SED.man+=		-e "s,share/man,${PKGMANDIR},"

# pkgsrc registers mime files using mimedb.mk (see below)
CONFIGURE_ARGS+=	--enable-packager-mode

# needs svg pixbuf loader at runtime
DEPENDS+=	librsvg-[0-9]*:../../graphics/librsvg
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

# setup.py target includes ${DESTDIR}, which is wrong
post-install:
	${ECHO} -n ${PREFIX}/share > ${DESTDIR}${PREFIX}/${PYSITELIB}/gramps/gen/utils/resource-path

.include "options.mk"

.include "../../databases/py-bsddb3/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/distutils.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../mk/bsd.pkg.mk"
