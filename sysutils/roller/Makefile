# $NetBSD: Makefile,v 1.24 2004/12/03 15:15:10 wiz Exp $
#

DISTNAME=		roller-1.18
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Roll log files

DEPENDS+=		cpogm-[0-9]*:../../sysutils/cpogm
DEPENDS+=		logtime-[0-9]*:../../time/logtime
DEPENDS+=		pflogsumm-[0-9]*:../../sysutils/pflogsumm

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		# defined
USE_PERL5=		# defined

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GAWK=${AWK}
MAKE_PARAMS+=		PERL=${PERL5}
MAKE_PARAMS+=		SH=${SH}

BUILD_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
