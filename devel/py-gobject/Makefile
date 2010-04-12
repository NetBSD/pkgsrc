# $NetBSD: Makefile,v 1.24 2010/04/12 14:00:17 taca Exp $
#

PKGNAME=		${PYPKGPREFIX}-gobject-2.18.0
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

PYTHON_VERSIONS_ACCEPTED=	26 25

post-patch:
	${SED} "s|@PYGTKCODEGEN@|${PREFIX}/share/pygobject/2.0|" \
	<${WRKSRC}/dsextras.py >${WRKSRC}/dsextras.py.tmp \
	&& ${MV} ${WRKSRC}/dsextras.py.tmp ${WRKSRC}/dsextras.py

BUILDLINK_API_DEPENDS.py-gobject-shared+= py-gobject-shared>=${PKGVERSION_NOREV}

.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
