# $NetBSD: Makefile,v 1.38 2011/11/26 04:39:51 sbd Exp $
#

DISTNAME=	tla-1.3.5
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	${MASTER_SITE_GNU:=gnu-arch/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://regexps.srparish.net/
COMMENT=	Revision control system ideal for widely distributed development

DEPENDS+=	patch-[0-9]*:../../devel/patch
DEPENDS+=	diffutils-[0-9]*:../../devel/diffutils
DEPENDS+=	gtar-base-[0-9]*:../../archivers/gtar-base

PKG_DESTDIR_SUPPORT=	user-destdir
PKG_INSTALLATION_TYPES=	overwrite pkgviews

CHECK_PORTABILITY_SKIP+=	\
	src/tla/tests/changeset-tests/chmod_random \
	src/tla/tests/changeset-tests/run-spaces-test.sh \
	src/tla/tests/changeset-tests/run-test.sh

MAKE_JOBS_SAFE=	no
REPLACE_BASH+=	src/tla/tests/changeset-tests/chmod_random
USE_TOOLS+=	bash
USE_TOOLS+=	gmake pax

HAS_CONFIGURE=		yes
OVERRIDE_GNU_CONFIG_SCRIPTS=	yes
OVERRIDE_DIRDEPTH=	3
CONFIGURE_DIRS=		src/=build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ARGS+=	--prefix=${PREFIX}
CONFIGURE_ARGS+=	--with-gnu-diff=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff
CONFIGURE_ARGS+=	--with-gnu-diff3=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}diff3
CONFIGURE_ARGS+=	--with-gnu-patch=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}patch
CONFIGURE_ARGS+=	--with-gnu-tar=${PREFIX}/bin/${GNU_PROGRAM_PREFIX}tar

DOCDIR=			${PREFIX}/share/doc/tla

post-extract:
	cd ${WRKSRC} && ${MKDIR} ${CONFIGURE_DIRS}

INSTALLATION_DIRS+=	bin ${DOCDIR}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/=build/tla/tla/tla ${DESTDIR}${PREFIX}/bin
	# Install arch documentation.
	cd ${WRKDIR}/${DISTNAME}/src/docs-tla &&		\
		${FIND} . \( -name \*.css -or -name \*.html	\
			-or -name \*.txt \) -print		\
		| pax -rwppm ${DESTDIR}${DOCDIR}
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${DOCDIR}
	${FIND} ${DESTDIR}${DOCDIR} -type d -print | ${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${DESTDIR}${DOCDIR} -type f -print | ${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
