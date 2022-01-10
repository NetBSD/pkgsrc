# $NetBSD: Makefile,v 1.34 2022/01/10 01:46:33 ryoon Exp $

DISTNAME=	gpick-0.2.6
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=thezbyg/}
GITHUB_TAG=	${DISTNAME}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/thezbyg/gpick/
COMMENT=	Advanced color picker
LICENSE=	modified-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config msgfmt msgmerge xgettext

GCC_REQD+=	5 # C++14

TOOL_DEPENDS+=	ragel-[0-9]*:../../devel/ragel

PYTHON_VERSIONS_ACCEPTED=	27	# as of 0.2.5

SCONS_ARGS+=	DESTDIR=${DESTDIR}${PREFIX}

SUBST_CLASSES+=		man
SUBST_STAGE.man=	pre-configure
SUBST_FILES.man+=	SConscript
SUBST_SED.man+=		-e "s,/share/man/man1,/${PKGMANDIR}/man1,g"

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS}

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${SCONSBIN} ${SCONS_ARGS} install

.include "../../devel/boost-libs/buildlink3.mk"
PYTHON_FOR_BUILD_ONLY?=	yes
.include "../../devel/scons/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
