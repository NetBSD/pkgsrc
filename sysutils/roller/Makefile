# $NetBSD: Makefile,v 1.34 2012/10/03 21:57:44 wiz Exp $
#

DISTNAME=		roller-1.20
#PKGREVISION=		1
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		# ftp://ftp.gw.com/pub/people/kim/

MAINTAINER=		kim@tac.nyc.ny.us
COMMENT=		Roll log files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		cpogm-[0-9]*:../../sysutils/cpogm
DEPENDS+=		logtime-[0-9]*:../../time/logtime
DEPENDS+=		pflogsumm-[0-9]*:../../sysutils/pflogsumm

.include "../../mk/bsd.prefs.mk"

NO_CONFIGURE=		yes
USE_TOOLS+=		perl:run

MAKE_FLAGS+=		PREFIX=${DESTDIR}${PREFIX}
MAKE_FLAGS+=		GAWK=${AWK}
MAKE_FLAGS+=		PERL=${PERL5}
MAKE_FLAGS+=		SH=${SH}

.include "../../mk/bsd.pkg.mk"
