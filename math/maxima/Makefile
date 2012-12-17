# $NetBSD: Makefile,v 1.36 2012/12/17 21:35:11 asau Exp $

DISTNAME=		maxima-5.29.1
# On updates, please make sure editors/TeXmacs knows about the new
# version number.
# (if needed, patch plugins/maxima/bin/{maxima_detect,tm_maxima})
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system
LICENSE=		gnu-gpl-v2

# Note: lisp backend is depended and setup up for in options.mk
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
USE_TOOLS+=		makeinfo perl
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
