# $NetBSD: Makefile,v 1.19 2003/11/12 01:31:49 salo Exp $

DISTNAME=	dia-0.91
PKGREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/dia/0.91/}

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
CONFIGURE_ARGS+=	--with-python

PYTHON_PATCH_SCRIPTS=	plug-ins/python/gtkcons.py

XSLT_FILE=	${WRKSRC}/plug-ins/xslt/xslt.c
post-patch:
	${MV} ${XSLT_FILE} ${XSLT_FILE}.pre
	${SED}  -e "s,%%PREFIX%%,${PREFIX},g" ${XSLT_FILE}.pre > ${XSLT_FILE}

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../x11/py-gtk2/buildlink2.mk"
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
