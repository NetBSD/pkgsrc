# $NetBSD: Makefile,v 1.3 2014/04/19 01:15:46 asau Exp $

DISTNAME=		w32api-3.11
PKGNAME=		mingw-w32api-bin-3.11
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GCC libraries for win32 cross-development

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_CROSSBASE=		yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS+=	${MINGW_TARGET}

do-install:
	cd ${WRKSRC} && pax -rw -pp include lib \
		${DESTDIR}${PREFIX}/${MINGW_TARGET}

.include "../../cross/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
