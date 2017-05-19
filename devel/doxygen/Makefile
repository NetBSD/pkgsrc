# $NetBSD: Makefile,v 1.132 2017/05/19 14:56:00 joerg Exp $

DISTNAME=	doxygen-1.8.13.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/
MASTER_SITES+=	http://ftp.stack.nl/pub/users/dimitri/

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
USE_LANGUAGES=		c c++
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

# Case Insensitive or Case Sensitive File System
PLIST_VARS+=		ci cs

# pangocairo: basic ps/pdf support via PKG_BUILD_OPTIONS.graphviz
PLIST_VARS+=		pangocairo nopangocairo

SUBST_CLASSES+=		perlbin
SUBST_STAGE.perlbin=	pre-configure
SUBST_MESSAGE.perlbin=	Fixing hardcoded path to the Perl interpreter
SUBST_FILES.perlbin=	examples/tag.cfg
SUBST_SED.perlbin=	-e 's,^PERL_PATH.*,PERL_PATH = ${PERL5},'

SUBST_CLASSES+=		epstopdf
SUBST_STAGE.epstopdf=	pre-configure
SUBST_MESSAGE.epstopdf=	Fixing path to epstopdf
SUBST_FILES.epstopdf=	src/diagram.cpp src/docparser.cpp src/dot.cpp \
			src/msc.cpp
SUBST_SED.epstopdf=	-e 's,"epstopdf","${PREFIX}/bin/epstopdf",g'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.ci=		yes	# case-insensitive
.else
PLIST.cs=		yes	# case-sensitive
.endif

CONFIGURE_ARGS.DragonFly+=	-platform freebsd-g++

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.12nb1
.include "../../graphics/graphviz/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.graphviz:Mpangocairo)
PLIST.pangocairo=	yes
.else
PLIST.nopangocairo=	yes
.endif
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
