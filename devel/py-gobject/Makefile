# $NetBSD: Makefile,v 1.62 2021/12/30 13:05:30 adam Exp $

PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/^py//}
PKGREVISION=	4

PYTHON_VERSIONED_DEPENDENCIES+=	cairo

PYTHON_VERSIONS_ACCEPTED=	37 27

.include "Makefile.common"

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
REPLACE_PYTHON+=	docs/xsl/fixxref.py.in

PYTHON_SELF_CONFLICT=	yes

BUILDLINK_API_DEPENDS.py-gobject-shared+=	py-gobject-shared>=${PKGVERSION_NOREV}

CONFIGURE_ARGS+=	--disable-introspection

.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
