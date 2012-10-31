# $NetBSD: Makefile,v 1.38 2012/10/31 11:16:57 asau Exp $

DISTNAME=		flex-2.5.36
PKGREVISION=		1
CATEGORIES=		lang
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=flex/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://flex.sourceforge.net/
COMMENT=		Fast clone of lex(1), the lexical scanner generator

# needed for building flex.pdf, make it an option?
#BUILD_DEPENDS+=		gtexinfo-[0-9]*:../../devel/gtexinfo
#BUILD_DEPENDS+=		tex-tex-[0-9]*:../../print/tex-tex
#BUILD_DEPENDS+=		tex-pdftex-[0-9]*:../../print/tex-pdftex
#BUILD_DEPENDS+=		tex-latex-fonts-[0-9]*:../../fonts/tex-latex-fonts

GNU_CONFIGURE=		YES
USE_TOOLS+=		gm4:run makeinfo
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

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
