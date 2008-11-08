# $NetBSD: Makefile,v 1.17 2008/11/08 00:15:26 wiz Exp $
#

PKGNAME=		${PYPKGPREFIX}-gobject-2.15.4
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

.include "Makefile.common"

post-patch:
	${SED} "s|@PYGTKCODEGEN@|${PREFIX}/share/pygtk/2.0|" \
	<${WRKSRC}/dsextras.py >${WRKSRC}/dsextras.py.tmp \
	&& ${MV} ${WRKSRC}/dsextras.py.tmp ${WRKSRC}/dsextras.py

BUILDLINK_API_DEPENDS.py-gobject-shared+= py-gobject-shared>=${PKGVERSION}

.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
