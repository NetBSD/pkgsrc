# $NetBSD: Makefile,v 1.10 2007/03/20 16:03:12 drochner Exp $
#

DISTNAME=		maxima-5.11.0
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

.include "../../mk/bsd.pkg.mk"
