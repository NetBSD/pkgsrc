# $NetBSD: Makefile,v 1.6 2000/06/10 18:06:27 kim Exp $
#

DISTNAME=		roller-1.4
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us

DEPENDS+=		cpogm-*:../../sysutils/cpogm
DEPENDS+=		logtime-*:../../sysutils/logtime

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
NO_PATCH=		yes
USE_PERL5=		yes

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GAWK=${AWK}
MAKE_PARAMS+=		PERL=${LOCALBASE}/bin/perl
MAKE_PARAMS+=		SH=${SH}

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
