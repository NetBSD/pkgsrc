# $NetBSD: Makefile,v 1.187 2024/05/27 12:36:13 adam Exp $

DISTNAME=	doxygen-1.11.0.src
PKGNAME=	${DISTNAME:S/.src//}
CATEGORIES=	devel
MASTER_SITES=	https://doxygen.nl/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.doxygen.nl/
COMMENT=	Documentation system for C++, Java, IDL and C
LICENSE=	gnu-gpl-v2

DEPENDS+=	graphviz-[0-9]*:../../graphics/graphviz

EXTRACT_USING=	gtar # Cannot restore extended attributes

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
UNLIMIT_RESOURCES+=	datasize
# doxygen changelog says at least this version of flex is required
FLEX_REQD+=		2.6.4
USE_LANGUAGES=		c c++
USE_CXX_FEATURES+=	c++17
USE_TOOLS+=		gmake gs:run perl:run bison flex
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

CMAKE_ARGS+=		-DDOC_INSTALL_DIR=share/doc/doxygen
CMAKE_ARGS+=		-DGIT_EXECUTABLE=git # avoid searching for git executable
TEST_TARGET=		tests

PYTHON_FOR_BUILD_ONLY=	tool

# Case Insensitive or Case Sensitive File System
PLIST_VARS+=		ci cs

SUBST_CLASSES+=		epstopdf
SUBST_STAGE.epstopdf=	pre-configure
SUBST_MESSAGE.epstopdf=	Fixing path to epstopdf
SUBST_FILES.epstopdf=	src/diagram.cpp src/docparser.cpp src/msc.cpp
SUBST_SED.epstopdf=	-e 's,"epstopdf","${PREFIX}/bin/epstopdf",g'

# Fixing $PWD / $(PWD) / $(HOME) for documentation
# The dollar sign should be inserted literally in the documentation
# doxygen always inserted the path => Completely remove dollar sign
SUBST_CLASSES+=			changelog
SUBST_STAGE.changelog=		pre-configure
SUBST_MESSAGE.changelog=	Fixing dollar sign for documentation
SUBST_FILES.changelog=		doc/changelog.dox
SUBST_SED.changelog=		-e 's,$$PWD,PWD,g'
SUBST_SED.changelog+=		-e 's,$$(PWD,(PWD,g'
SUBST_SED.changelog+=		-e 's,$$(HOME,(HOME,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.ci=		yes	# case-insensitive
.else
PLIST.cs=		yes	# case-sensitive
.endif

CONFIGURE_ARGS.DragonFly+=	-platform freebsd-g++

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

.include "options.mk"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxyindexer.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxysearch.1
.if empty(PKG_OPTIONS:Mqt)
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxywizard.1
.endif

.include "../../mk/bsd.prefs.mk"
# wiz 20231103:
# as of doxygen 1.9.8, the ninja generator has problems in some environments:
# ninja: error: manifest 'build.ninja' still dirty after 100 tries, perhaps system time is not set
CMAKE_GENERATOR=	make

.include "../../devel/cmake/build.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
