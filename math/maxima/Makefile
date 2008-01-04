# $NetBSD: Makefile,v 1.16 2008/01/04 18:49:14 joerg Exp $
#

DISTNAME=		maxima-5.14.0
# On updates, please make sure editors/TeXmacs knows about the new
# version number.
# (if needed, patch plugins/maxima/bin/{maxima_detect,tm_maxima})
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system

DEPENDS+=		clisp-[0-9]*:../../lang/clisp
DEPENDS+=		tk-[0-9]*:../../x11/tk

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-clisp
USE_TOOLS+=		perl
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
