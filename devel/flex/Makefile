# $NetBSD: Makefile,v 1.31 2009/02/25 21:03:01 sno Exp $

DISTNAME=		flex-2.5.35
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://flex.sourceforge.net/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		bison gm4:run makeinfo
MAKE_JOBS_SAFE=		no
TEST_TARGET=		check
INFO_FILES=		yes
LIBS.SunOS+=		-lm
USE_PKGLOCALEDIR=	YES

.include "../../mk/bsd.prefs.mk"

.if ${LOWER_OPSYS} == "aix"
CFLAGS+=		-D_LINUX_SOURCE_COMPAT
.endif

#.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake	# bmake has problems with the test suite
#.endif

post-install:
	cd ${DESTDIR:Q}${PREFIX:Q}/bin && ln -s flex flex++

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
