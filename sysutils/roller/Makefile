# $NetBSD: Makefile,v 1.29 2005/09/28 20:52:27 rillig Exp $
#

DISTNAME=		roller-1.19
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Roll log files

DEPENDS+=		cpogm-[0-9]*:../../sysutils/cpogm
DEPENDS+=		logtime-[0-9]*:../../time/logtime
DEPENDS+=		netname-[0-9]*:../../net/netname
DEPENDS+=		pflogsumm-[0-9]*:../../sysutils/pflogsumm

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run

MAKE_PARAMS+=		PREFIX=${PREFIX}
MAKE_PARAMS+=		GAWK=${AWK}
MAKE_PARAMS+=		PERL=${PERL5}
MAKE_PARAMS+=		SH=${SH}

BUILD_TARGET=		all ${MAKE_PARAMS}
INSTALL_TARGET=		install ${MAKE_PARAMS}

.include "../../mk/bsd.pkg.mk"
