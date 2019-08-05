# $NetBSD: Makefile,v 1.138 2019/08/05 15:36:44 adam Exp $

DISTNAME=	doxygen-1.8.15.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://doxygen.nl/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
UNLIMIT_RESOURCES+=	datasize
# doxygen upstream uses this version of flex
FLEX_REQD=		2.5.35
USE_TOOLS+=		gmake gs:run perl:run bison flex
USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

CMAKE_ARGS+=		-DDOC_INSTALL_DIR:STRING=share/doc/doxygen
TEST_TARGET=		tests

# Case Insensitive or Case Sensitive File System
PLIST_VARS+=		ci cs

SUBST_CLASSES+=		perlbin
SUBST_STAGE.perlbin=	pre-configure
SUBST_MESSAGE.perlbin=	Fixing hardcoded path to the Perl interpreter
SUBST_FILES.perlbin=	examples/tag.cfg
SUBST_SED.perlbin=	-e 's,^PERL_PATH.*,PERL_PATH = ${PERL5},'

SUBST_CLASSES+=		epstopdf
SUBST_STAGE.epstopdf=	pre-configure
SUBST_MESSAGE.epstopdf=	Fixing path to epstopdf
SUBST_FILES.epstopdf=	src/diagram.cpp src/docparser.cpp src/msc.cpp
SUBST_SED.epstopdf=	-e 's,"epstopdf","${PREFIX}/bin/epstopdf",g'

# Fixing $PWD / $(PWD) / $(HOME) for documentation
# The dollar sign should be inserted literally in the documentation
# doxygen always inserted the path => Completely remove dollar sign
SUBST_CLASSES+=		changelog
SUBST_STAGE.changelog=	pre-configure
SUBST_MESSAGE.changelog=Fixing dollar sign for documentation
SUBST_FILES.changelog=	doc/changelog.doc
SUBST_SED.changelog=	-e 's,$$PWD,PWD,g'
SUBST_SED.changelog+=	-e 's,$$(PWD,(PWD,g'
SUBST_SED.changelog+=	-e 's,$$(HOME,(HOME,g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.ci=		yes	# case-insensitive
.else
PLIST.cs=		yes	# case-sensitive
.endif

CONFIGURE_ARGS.DragonFly+=	-platform freebsd-g++

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxyindexer.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxysearch.1
	${RM} -f ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/doxywizard.1

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.12nb1
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
