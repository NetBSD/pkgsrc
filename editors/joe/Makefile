# $NetBSD: Makefile,v 1.36 2012/10/03 11:43:35 asau Exp $

DISTNAME=	joe-3.7
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=joe-editor/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://joe-editor.sourceforge.net/
COMMENT=	Joe's own editor
LICENSE=	gnu-gpl-v1

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFBASEDIR}

PKG_SYSCONFSUBDIR=	joe

EGDIR=		${PREFIX}/share/examples/joe
CONF_FILES=	${EGDIR}/ftyperc ${PKG_SYSCONFDIR}/ftyperc
CONF_FILES+=	${EGDIR}/jicerc.ru ${PKG_SYSCONFDIR}/jicerc.ru
CONF_FILES+=	${EGDIR}/jmacsrc ${PKG_SYSCONFDIR}/jmacsrc
CONF_FILES+=	${EGDIR}/joerc ${PKG_SYSCONFDIR}/joerc
CONF_FILES+=	${EGDIR}/jpicorc ${PKG_SYSCONFDIR}/jpicorc
CONF_FILES+=	${EGDIR}/jstarrc ${PKG_SYSCONFDIR}/jstarrc
CONF_FILES+=	${EGDIR}/rjoerc ${PKG_SYSCONFDIR}/rjoerc

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
