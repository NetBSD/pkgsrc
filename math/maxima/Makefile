# $NetBSD: Makefile,v 1.13 2008/01/03 20:13:25 tonio Exp $
#

DISTNAME=		maxima-5.14.0
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
REPLACE_SH=		doc/misc/grepforvariables.sh

INFO_FILES=		yes
TEST_TARGET=		check

.include "../../mk/bsd.pkg.mk"
