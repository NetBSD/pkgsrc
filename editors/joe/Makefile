# $NetBSD: Makefile,v 1.32 2010/06/23 12:52:42 adam Exp $

DISTNAME=	joe-3.7
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=joe-editor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://joe-editor.sourceforge.net/
COMMENT=	Joe's own editor

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

INSTALLATION_DIRS+=	${PKG_SYSCONFDIR}/joe

EGDIR=		${PREFIX}/share/examples/joe
CONF_FILES=	${EGDIR}/ftyperc ${PKG_SYSCONFDIR}/joe/ftyperc
CONF_FILES+=	${EGDIR}/jicerc.ru ${PKG_SYSCONFDIR}/joe/jicerc.ru
CONF_FILES+=	${EGDIR}/jmacsrc ${PKG_SYSCONFDIR}/joe/jmacsrc
CONF_FILES+=	${EGDIR}/joerc ${PKG_SYSCONFDIR}/joe/joerc
CONF_FILES+=	${EGDIR}/jpicorc ${PKG_SYSCONFDIR}/joe/jpicorc
CONF_FILES+=	${EGDIR}/jstarrc ${PKG_SYSCONFDIR}/joe/jstarrc
CONF_FILES+=	${EGDIR}/rjoerc ${PKG_SYSCONFDIR}/joe/rjoerc

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
