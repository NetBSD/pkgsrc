# $NetBSD: Makefile,v 1.35 2004/10/14 17:04:08 jmmv Exp $

DISTNAME=	dia-0.94
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dia/0.94/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.gnome.org/projects/dia/
COMMENT=	Program for creating diagrams of all kinds

USE_BUILDLINK3=		YES
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN}
CONFIGURE_ARGS+=	--enable-gnome
CONFIGURE_ARGS+=	--enable-bonobo
CONFIGURE_ARGS+=	--with-python

PYTHON_PATCH_SCRIPTS=	po-checktrans.py
PYTHON_PATCH_SCRIPTS+=	plug-ins/python/gtkcons.py
PYTHON_PATCH_SCRIPTS+=	sheets/checktrans.py

INTL_FILE=     ${WRKSRC}/lib/intl.c
post-patch:
	${MV} ${INTL_FILE} ${INTL_FILE}.pre
	${SED}  -e "s,%%PREFIX%%,${PREFIX},g" ${INTL_FILE}.pre > ${INTL_FILE}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
