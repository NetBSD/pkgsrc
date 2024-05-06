# $NetBSD: Makefile,v 1.57 2024/05/06 08:40:25 jperkin Exp $

DISTNAME=	ski-1.3.2
PKGREVISION=	36
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=ski/}

MAINTAINER=	cherry@zyx.in
HOMEPAGE=	http://ski.sourceforge.net/
COMMENT=	The ia64 instruction set simulator
LICENSE=	gnu-gpl-v2

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

TOOL_DEPENDS+=	libelf>=0.8.13:../../devel/libelf

GNU_CONFIGURE=		yes
USE_LANGUAGES+=		c c++
CONFIGURE_ARGS+=	--prefix=${PREFIX}

CPPFLAGS+=	-I${PREFIX}/include/libelf -L ${PREFIX}/lib

# XXX prevent thousands of warnings for combfns
#CFLAGS+=	-Wno-unused-variable -Wno-unused-but-set-variable

USE_TOOLS+=	pkg-config aclocal autoconf automake autoreconf yacc
USE_LIBTOOL=	yes

SUBST_CLASSES+=		xski-app
SUBST_STAGE.xski-app=	pre-configure
SUBST_MESSAGE.xski-app=	Fixing X11 Makefile.am app-default paths.
SUBST_FILES.xski-app=	Makefile.am
SUBST_SED.xski-app=	-e 's,/etc/X11/app-defaults,${PREFIX}/lib/X11/app-defaults,g'

SUBST_CLASSES+=		ssx-app
SUBST_STAGE.ssx-app=	pre-configure
SUBST_MESSAGE.ssx-app=	Fixing X11 ssX.c app-default paths.
SUBST_FILES.ssx-app=	src/ssX.c
SUBST_SED.ssx-app=	-e 's,XSKI_RESOURCE_FILE,${PREFIX}/lib/X11/app-defaults/XSki,g'

pre-configure:
#	cd  ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${SH} ./autogen.sh ${CONFIGURE_ARGS}
	cd ${WRKSRC} && autoreconf -fi -I macros

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/manual/SkiManualMasterDoc.pdf \
			${DESTDIR}${PREFIX}/share/ski

.include "../../devel/gperf/buildlink3.mk"
.include "../../devel/libelf/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
