# $NetBSD: Makefile,v 1.23 2009/10/26 20:08:21 joerg Exp $
#

PKGNAME=		${PYPKGPREFIX}-gobject-2.18.0

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
