# $NetBSD: Makefile,v 1.3 2002/09/21 23:46:51 jlam Exp $
#

DISTNAME=	pygimp-1.2
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.daa.com.au/pub/james/pygimp/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.daa.com.au/~james/pygimp/
COMMENT=	Python interface to the GIMP

GNU_CONFIGURE=	YES
CONFIGURE_ENV+=	PYTHON=${PYTHONBIN}
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE= ${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY= yes

PYTHON_PATCH_SCRIPTS= plug-ins/clothify.py plug-ins/foggify.py
PYTHON_PATCH_SCRIPTS+= plug-ins/gimpcons.py plug-ins/gtkcons.py
PYTHON_PATCH_SCRIPTS+= plug-ins/pdbbrowse.py plug-ins/shadow_bevel.py
PYTHON_PATCH_SCRIPTS+= plug-ins/sphere.py plug-ins/whirlpinch.py
PY_PATCHPLIST=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/pygimp
	for i in ${WRKSRC}/doc/*.html; do \
		${INSTALL_DATA} $$i ${PREFIX}/share/doc/pygimp; \
	done

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../graphics/gimp-base/buildlink.mk"
.include "../../x11/pygtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
