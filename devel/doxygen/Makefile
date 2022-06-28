# $NetBSD: Makefile,v 1.161 2022/06/28 11:31:42 wiz Exp $

DISTNAME=	doxygen-1.9.4.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://doxygen.nl/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
UNLIMIT_RESOURCES+=	datasize
# doxygen changelog says at least this version of flex is required
FLEX_REQD=		2.6.4
# doxygen changelog says a C++17 compiler is required. Uses -std=gnu++1z
# Native std::filesystem requires GCC 9. Patch for emulation is still present
# Tested to work with GCC 7.5.0 from NetBSD 9.2
GCC_REQD+=		5
USE_CMAKE=		yes
USE_LANGUAGES=		c c++
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
SUBST_FILES.changelog=		doc/changelog.doc
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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
