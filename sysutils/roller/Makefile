# $NetBSD: Makefile,v 1.12 2001/02/17 17:42:17 wiz Exp $
#

DISTNAME=		roller-1.7
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		roll log files

DEPENDS+=		cpogm-*:../../sysutils/cpogm
DEPENDS+=		logtime-*:../../time/logtime

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		# defined
NO_PATCH=		# defined
USE_PERL5=		# defined

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GAWK=${AWK}
MAKE_PARAMS+=		PERL=${PERL5}
MAKE_PARAMS+=		SH=${SH}

ALL_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
