# $NetBSD: Makefile,v 1.7 2020/03/20 11:57:25 nia Exp $

DISTNAME=		w32api-3.11
PKGNAME=		mingw-w32api-bin-3.11
PKGREVISION=		1
CATEGORIES=		cross
MASTER_SITES=		${MASTER_SITE_MINGW}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mingw.sourceforge.net/
COMMENT=		GCC libraries for win32 cross-development

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_TOOLS+=		pax
WRKSRC=			${WRKDIR}

INSTALLATION_DIRS+=	${MINGW_TARGET}

do-install:
	cd ${WRKSRC} && pax -rw -pp include lib \
		${DESTDIR}${PREFIX}/cross/${MINGW_TARGET}

.include "../../cross/mingw/Makefile.common"
.include "../../mk/bsd.pkg.mk"
