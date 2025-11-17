# $NetBSD: Makefile,v 1.64 2025/11/17 11:01:07 wiz Exp $

DISTNAME=		maxima-5.44.0
PKGREVISION=		5
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://maxima.sourceforge.net/
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
