# $NetBSD: Makefile,v 1.1 2014/08/25 22:07:28 schmonz Exp $

DISTNAME=		wemux-3.2.0
CATEGORIES=		misc
MASTER_SITES=		http://www.c-s.li/ports/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/zolrath/wemux
COMMENT=		Easier, more powerful multi-user terminal multiplexing
LICENSE=		mit

DEPENDS+=		tmux>=1.6:../../misc/tmux

WRKSRC=			${WRKDIR}/zolrath-wemux-971f8c3

USE_LANGUAGES=		# none
NO_BUILD=		yes
USE_TOOLS+=		bash
REPLACE_BASH+=		wemux

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	do-configure
SUBST_FILES.paths=	wemux
SUBST_SED.paths=	-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|g'

EGDIR=			share/examples/${PKGBASE}
CONF_FILES+=		${PREFIX}/${EGDIR}/wemux.conf ${PKG_SYSCONFDIR}/wemux.conf
INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 ${EGDIR}

do-install:
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} wemux ${DESTDIR}${PREFIX}/bin/ && \
	${INSTALL_MAN} man/wemux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ && \
	${INSTALL_DATA} wemux.conf.example ${DESTDIR}${PREFIX}/${EGDIR}/wemux.conf

.include "../../mk/bsd.pkg.mk"
