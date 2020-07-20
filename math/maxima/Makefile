# $NetBSD: Makefile,v 1.58 2020/07/20 06:42:31 yhardy Exp $

DISTNAME=		maxima-5.44.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system
LICENSE=		gnu-gpl-v2

# Note: lisp backend is depended and setup up for in options.mk
DEPENDS+=		tk-[0-9]*:../../x11/tk

CHECK_PORTABILITY_SKIP=	doc/info/fix_tab

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake makeinfo perl
TEXINFO_REQD=		5.0

INFO_FILES=		yes
TEST_TARGET=		check
PYTHON_FOR_BUILD_ONLY=	yes

.include "options.mk"

.include "../../lang/python/application.mk"
.include "../../mk/bsd.pkg.mk"
