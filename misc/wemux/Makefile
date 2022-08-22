# $NetBSD: Makefile,v 1.2 2022/08/22 19:22:04 tnn Exp $

DISTNAME=		wemux-3.2.0.20150823
CATEGORIES=		misc
MASTER_SITES=		${MASTER_SITE_GITHUB:=zolrath/}
GITHUB_TAG=		01c6541f8deceff372711241db2a13f21c4b210c

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		https://github.com/zolrath/wemux
COMMENT=		Easier, more powerful multi-user terminal multiplexing
LICENSE=		mit

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

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD" && exists(/usr/bin/tmux)
# already have tmux in base
.else
DEPENDS+=		tmux>=1.6:../../misc/tmux
.endif

do-install:
	cd ${WRKSRC} && \
	${INSTALL_SCRIPT} wemux ${DESTDIR}${PREFIX}/bin/ && \
	${INSTALL_MAN} man/wemux.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/ && \
	${INSTALL_DATA} wemux.conf.example ${DESTDIR}${PREFIX}/${EGDIR}/wemux.conf

.include "../../mk/bsd.pkg.mk"
