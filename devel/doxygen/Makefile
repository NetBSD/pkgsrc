# $NetBSD: Makefile,v 1.53 2006/10/28 02:44:58 dsainty Exp $

DISTNAME=	doxygen-1.4.7.src
PKGNAME=	doxygen-1.4.7
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.stack.nl/pub/users/dimitri/ \
		http://ftp.stack.nl/pub/users/dimitri/

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.doxygen.org/
COMMENT=	Documentation system for C++, Java, IDL and C

TEX_ACCEPTED=	teTeX3
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_TOOLS+=		gmake gs:run perl:run flex
USE_LANGUAGES=		c c++
HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--make ${GMAKE}
CONFIGURE_ARGS+=	--perl ${PERL5}
CONFIGURE_ARGS+=	--install ${INSTALL}
CONFIGURE_ARGS+=	--dot ${PREFIX}/bin/dot
CONFIGURE_ARGS+=	--prefix ${PREFIX}
CONFIGURE_ARGS+=	--docdir ${PREFIX}/share/doc
MAKE_ENV+=		PKGSRC_CFLAGS=${CFLAGS:M*:Q}
MAKE_FLAGS+=		MAN1DIR=${PKGMANDIR}/man1

# Workaround for "configure" issue under Solaris, where PWD is more likely
# to be set to the working directory of the Pkgsrc "make" than the working
# directory, because Solaris /bin/sh does not support PWD.  An empty PWD
# will also fail, because configure's "test -z $PWD" will error if PWD is
# unset (PWD should be quoted).
CONFIGURE_ENV+=		PWD=${WRKSRC:Q}

.if exists(./descr)
PLIST_SUBST+=	CASESENSITIVE="@comment " CASEINSENSITIVE=""
.else
PLIST_SUBST+=	CASESENSITIVE="" CASEINSENSITIVE="@comment "
.endif

SUBST_CLASSES+=		pybin
SUBST_STAGE.pybin=	pre-configure
SUBST_FILES.pybin=	doc/Makefile.in
SUBST_SED.pybin=	-e "s|@PYTHONBIN@|${PYTHONBIN}|g"

SUBST_CLASSES+=		perlbin
SUBST_STAGE.perlbin=	pre-configure
SUBST_MESSAGE.perlbin=	Fixing hardcoded path to the Perl interpreter
SUBST_FILES.perlbin=	examples/tag.cfg
SUBST_SED.perlbin=	-e 's,^PERL_PATH.*,PERL_PATH = ${PERL5},'

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "DragonFly"
CONFIGURE_ARGS+=	-platform freebsd-g++
.endif

post-patch:
	${TOUCH} ${WRKSRC}/src/doxytag.l

post-install:
	cd ${WRKSRC} && ${GMAKE} install_docs

.include "../../graphics/graphviz/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../mk/tex.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
