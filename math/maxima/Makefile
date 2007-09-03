# $NetBSD: Makefile,v 1.12 2007/09/03 16:08:47 drochner Exp $
#

DISTNAME=		maxima-5.13.0
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=maxima/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://maxima.sourceforge.net/
COMMENT=		Computer algebra system

DEPENDS+=		clisp-[0-9]*:../../lang/clisp
DEPENDS+=		tk-[0-9]*:../../x11/tk

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-clisp
USE_TOOLS+=		perl

INFO_FILES=		# PLIST
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
