# $NetBSD: Makefile,v 1.23 2007/03/07 16:50:13 rillig Exp $

DISTNAME=		flex-2.5.33
PKGREVISION=		2
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnu.org/software/flex/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison gm4:run makeinfo
MAKE_JOBS_SAFE=		no
TEST_TARGET=		check
INFO_FILES=		yes
CPPFLAGS.IRIX+=		-DHAVE_ALLOCA_H		# bug #1675899
LIBS.SunOS+=		-lm
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake	# bmake has problems with the test suite
.endif

post-install:
	cd ${PREFIX}/bin && ln -s flex flex++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
