# $NetBSD: Makefile,v 1.30 2006/03/11 11:13:51 kim Exp $
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

MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		GAWK=${AWK}
MAKE_FLAGS+=		PERL=${PERL5}
MAKE_FLAGS+=		SH=${SH}

BUILD_TARGET=		all
INSTALL_TARGET=		install

.include "../../mk/bsd.pkg.mk"
