# $NetBSD: Makefile,v 1.10 2007/04/10 16:42:57 drochner Exp $
#

PKGNAME=		${PYPKGPREFIX}-gobject-2.12.3

PKGREVISION=	1

.include "Makefile.common"

post-patch:
	${SED} "s|@PYGTKCODEGEN@|${PREFIX}/share/pygtk/2.0|" \
	<${WRKSRC}/dsextras.py >${WRKSRC}/dsextras.py.tmp \
	&& ${MV} ${WRKSRC}/dsextras.py.tmp ${WRKSRC}/dsextras.py

.include "../../lang/python/extension.mk"
.include "../../devel/py-gobject-shared/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
