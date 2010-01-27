# $NetBSD: Makefile,v 1.32 2010/01/27 19:53:23 joerg Exp $
#

DISTNAME=		roller-1.20
#PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://ftp.gw.com/pub/people/kim/

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
