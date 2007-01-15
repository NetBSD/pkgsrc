# $NetBSD: Makefile,v 1.19 2007/01/15 06:23:47 rillig Exp $

DISTNAME=		flex-2.5.33
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison
MAKE_JOBS_SAFE=		no
TEST_TARGET=		check
INFO_FILES=		yes
LIBS.SunOS+=		-lm

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake	# bmake has problems with the test suite
.endif

post-install:
	cd ${PREFIX}/bin && ln -s flex flex++

.include "../../mk/bsd.pkg.mk"
