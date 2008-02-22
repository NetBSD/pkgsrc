# $NetBSD: Makefile,v 1.28 2008/02/22 22:13:33 tnn Exp $

DISTNAME=		flex-2.5.34
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison gm4:run makeinfo
MAKE_JOBS_SAFE=		no
TEST_TARGET=		check
INFO_FILES=		yes
LIBS.SunOS+=		-lm
USE_PKGLOCALEDIR=	YES

do-build:
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}
	@${STEP_MSG} "Regenerating the scanner"
	${RUN} cd ${WRKSRC} && ./flex -o scan.c scan.l
	@${STEP_MSG} "Rebuilding flex"
	${RUN} cd ${WRKSRC} && ${BUILD_MAKE_CMD} ${BUILD_TARGET}

.include "../../mk/bsd.prefs.mk"

#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake	# bmake has problems with the test suite
#.endif

post-install:
	cd ${DESTDIR:Q}${PREFIX:Q}/bin && ln -s flex flex++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
