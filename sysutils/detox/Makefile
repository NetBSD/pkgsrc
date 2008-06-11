# $NetBSD: Makefile,v 1.5 2008/06/11 13:56:29 obache Exp $
#

DISTNAME=		detox-1.2.0
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=detox/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz.kuzma@gmail.com
HOMEPAGE=		http://detox.sourceforge.net/
COMMENT=		Removes non-standard characters from filenames

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_TOOLS+=		lex gmake
INSTALL_TARGET=		install-base install-unsafe-config

EGDIR=			${PREFIX}/share/examples/detox
CONF_FILES=		${EGDIR}/detoxrc ${PKG_SYSCONFDIR}/detoxrc

post-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/detoxrc ${DESTDIR}${EGDIR}/detoxrc

.include "../../mk/bsd.pkg.mk"
