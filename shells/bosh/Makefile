# $NetBSD: Makefile,v 1.12 2020/06/05 17:20:52 micha Exp $

DISTNAME=	schily-2020-05-25
PKGNAME=	bosh-20200525
CATEGORIES=	shells
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=schilytools/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://sourceforge.net/projects/schilytools/
COMMENT=	The Schily Bourne Shell
LICENSE=	cddl-1.0

MAKE_JOBS_SAFE=	no

.include "../../mk/bsd.prefs.mk"

TOOL_DEPENDS+=	smake-[0-9]*:../../devel/smake
SMAKE=		MAKEFLAGS= smake
MAKE_FLAGS+=	DESTDIR=${DESTDIR} INS_BASE=${PREFIX} DEFMANBASE=. MANDIR=${PKGMANDIR}
# Honor CPPFLAGS, CFLAGS and LDFLAGS
MAKE_FLAGS+=	CPPOPTX=${CPPFLAGS:Q} COPTX=${CFLAGS:Q} LDOPTX=${LDFLAGS:Q}

PKG_SHELL=		bin/bosh
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

# Only required for testsuite
# This is a temporary workaround for NetBSD. Next release will contain some
# test logic and this can be removed again
.if ${OPSYS} == "NetBSD"
SUBST_CLASSES+=			fix-paths
SUBST_STAGE.fix-paths=		pre-test
SUBST_MESSAGE.fix-paths=	Fixing absolute paths for true and false.
SUBST_FILES.fix-paths=		sh/tests/shelltests/trap/trap.sh
SUBST_SED.fix-paths=		-e 's,/bin/true,/usr/bin/true,g'
SUBST_SED.fix-paths+=		-e 's,/bin/false,/usr/bin/false,g'
.endif

# Shared platform specific code for schilytools (provided by smake package)
.include "../../devel/smake/Makefile.common"

do-configure:
	cd ${WRKSRC}/inc && ${SMAKE} ${MAKE_FLAGS}

do-build:
	cd ${WRKSRC} && for library in					\
		libschily libxtermcap libfind libgetopt libshedit;	\
	do								\
		cd ${WRKSRC}/$${library} && ${SMAKE} ${MAKE_FLAGS};	\
	done
	cd ${WRKSRC}/sh && ${SMAKE} ${MAKE_FLAGS}

# Process tables in manpage
post-build:
.if !empty(USE_TOOLS:Mtbl)
	cd ${WRKSRC} && ${TBL} sh/sh.1 >sh/bosh.1.tmp;			\
		${MV} -f sh/bosh.1.tmp sh/bosh.1
.else
	cd ${WRKSRC} && ${MV} -f sh/sh.1 sh/bosh.1
.endif

do-test:
	cd ${WRKSRC}/sh &&						\
		cd tests; ${SMAKE} ${MAKE_FLAGS} tests

do-install:
	cd ${WRKSRC}/sh &&						\
		${INSTALL_PROGRAM} ${WRKSRC}/sh/OBJ/*/sh		\
			${DESTDIR}${PREFIX}/bin/bosh;			\
		${INSTALL_MAN} ${WRKSRC}/sh/bosh.1			\
			${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
