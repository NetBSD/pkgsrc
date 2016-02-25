# $NetBSD: Makefile,v 1.123 2016/02/25 12:12:47 jperkin Exp $

DISTNAME=	doxygen-1.8.9.1.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
UNLIMIT_RESOURCES+=	datasize
# doxygen upstream uses this version of flex
FLEX_REQD=		2.5.35
USE_TOOLS+=		gmake gs:run perl:run bison flex
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--make ${GMAKE}
CONFIGURE_ARGS+=	--perl ${PERL5}
CONFIGURE_ARGS+=	--python ${PYTHONBIN}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--dot ${PREFIX}/bin/dot
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc/doxygen
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

REPLACE_PERL=		tmake/bin/tmake

PYTHON_VERSIONS_INCOMPATIBLE=	33 34 35 # not yet ported as of 1.8.6

# Case Insensitive or Case Sensitive File System
PLIST_VARS+=		ci cs

# pangocairo: basic ps/pdf support via PKG_BUILD_OPTIONS.graphviz
PLIST_VARS+=		pangocairo nopangocairo

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_FILES.path=	doc/Makefile.in
SUBST_SED.path=		-e "s|@EPSTOPDF@|${PREFIX}/bin/epstopdf|g"

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

# Just install the binary and the man page.  (If the latex option
# is enabled, this target will be augmented.)
INSTALL_TARGET=		install

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
PLIST.ci=		yes	# case-insensitive
.else
PLIST.cs=		yes	# case-sensitive
.endif

CONFIGURE_ARGS.DragonFly+=	-platform freebsd-g++

LDFLAGS+=		${BUILDLINK_LDADD.iconv}

post-patch:
	touch ${WRKSRC}/src/doxytag.l

# remove unnecessary files that leak tool paths
post-install:
	rm -f ${DESTDIR}${PREFIX}/share/doc/doxygen/examples/Makefile*

BUILDLINK_API_DEPENDS.graphviz+=	graphviz>=2.12nb1

.include "options.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"

.if !empty(PKG_BUILD_OPTIONS.graphviz:Mpangocairo)
PLIST.pangocairo=	yes
.else
PLIST.nopangocairo=	yes
.endif
.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
