# $NetBSD: Makefile,v 1.20 2003/12/02 22:32:48 recht Exp $

DISTNAME=	dia-0.92.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dia/0.92/}

MAINTAINER=	jmcneill@invisible.yi.org
HOMEPAGE=	http://www.lysator.liu.se/~alla/dia/
COMMENT=	Program for creating diagrams of all kinds

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_BUILDLINK2=		YES
USE_PKGLOCALEDIR=	YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
