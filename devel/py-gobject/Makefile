# $NetBSD: Makefile,v 1.29 2011/01/13 13:37:26 wiz Exp $
#

PKGNAME=		${PYPKGPREFIX}-gobject-2.26.0
PKGREVISION=		2

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PYTHON_VERSIONS_ACCEPTED=	26 25

SUBST_CLASSES+=		codegen
SUBST_STAGE.codegen=	pre-configure
SUBST_FILES.codegen=	dsextras.py
SUBST_SED.codegen=	-e "s|@PYGTKCODEGEN@|${PREFIX}/share/pygobject/2.0|"

REPLACE_PYTHON+=	codegen/code-coverage.py
REPLACE_PYTHON+=	codegen/codegen.py
REPLACE_PYTHON+=	codegen/createdefs.py
REPLACE_PYTHON+=	codegen/defsconvert.py
REPLACE_PYTHON+=	codegen/defsgen.py
REPLACE_PYTHON+=	codegen/docextract_to_xml.py
REPLACE_PYTHON+=	codegen/docgen.py
REPLACE_PYTHON+=	codegen/h2def.py
REPLACE_PYTHON+=	codegen/mergedefs.py
REPLACE_PYTHON+=	codegen/missingdefs.py
REPLACE_PYTHON+=	codegen/mkskel.py
REPLACE_PYTHON+=	codegen/scanvirtuals.py
REPLACE_PYTHON+=	codegen/scmexpr.py

BUILDLINK_API_DEPENDS.py-gobject-shared+= py-gobject-shared>=${PKGVERSION_NOREV}

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/py-cairo/buildlink3.mk"
.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
