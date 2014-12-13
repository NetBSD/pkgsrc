# $NetBSD: Makefile,v 1.3 2014/12/13 14:27:35 mef Exp $

DISTNAME=	wgetpaste-2.25
CATEGORIES=	net www
MASTER_SITES=	http://wgetpaste.zlin.dk/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://wgetpaste.zlin.dk/
COMMENT=	Command line utility to upload to pastebin sites
LICENSE=	public-domain

DEPENDS+=	wget>=1.13.4:../../net/wget

INSTALLATION_DIRS=	bin share/examples/wgetpaste etc
NO_BUILD=		yes

CONF_FILES=		${PREFIX}/share/examples/wgetpaste/wgetpaste.conf ${PKG_SYSCONFDIR}/wgetpaste.conf

SUBST_CLASSES+=		config
SUBST_SED.config+=	-e "s,/etc/,${PKG_SYSCONFDIR}/,g"
SUBST_FILES.config+=	wgetpaste
SUBST_STAGE.config=	pre-install
SUBST_MESSAGE.config=	Fixing path to global config files.

USE_TOOLS+=		bash:run
REPLACE_BASH=		wgetpaste

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/wgetpaste ${DESTDIR}${PREFIX}/bin/wgetpaste
	${INSTALL_DATA} ${FILESDIR}/wgetpaste.conf ${DESTDIR}${PREFIX}/share/examples/wgetpaste/wgetpaste.conf

.include "../../mk/bsd.pkg.mk"
