# $NetBSD: Makefile,v 1.7 2020/04/09 12:40:20 fox Exp $

DISTNAME=	foliate-2.1.1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_GITHUB:=johnfactotum/}
EXTRACT_USING=	bsdtar

MAINTAINER=	fox@NetBSD.org
COMMENT=	Simple and modern GTK eBook viewer
HOMEPAGE=	https://johnfactotum.github.io/foliate/
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config msgfmt xgettext

DEPENDS+=	gjs>=1.52.0:../../lang/gjs

SUBST_CLASSES+=		pyvers
SUBST_MESSAGE.pyvers=	Substitute the correct python version.
SUBST_STAGE.pyvers=	pre-configure
SUBST_FILES.pyvers=	src/epubView.js
SUBST_VARS.pyvers+=	PYVERSSUFFIX

# Fails without GNU msgfmt
USE_BUILTIN.gettext=	no

REPLACE_PYTHON+=	build-aux/meson/postinstall.py
REPLACE_PYTHON+=	src/assets/KindleUnpack/*.py

INSTALLATION_DIRS+=	libexec/foliate

pre-install:
	${RM} -f ${WRKSRC}/src/assets/KindleUnpack/*.orig

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/com.github.johnfactotum.Foliate \
		${DESTDIR}${PREFIX}/libexec/foliate/com.github.johnfactotum.Foliate
	${LN} -s -f ${DESTDIR}${PREFIX}/libexec/foliate/com.github.johnfactotum.Foliate \
		${DESTDIR}${PREFIX}/bin/foliate

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.webkit-gtk+=	webkit-gtk>=2.24.0
.include "../../www/webkit-gtk/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
