# $NetBSD: Makefile,v 1.45 2018/11/19 14:50:24 nia Exp $

DISTNAME=	gajim-1.1.0
PKGREVISION=	1
CATEGORIES=	chat python
MASTER_SITES=	https://www.gajim.org/downloads/1.1/

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	http://www.gajim.org/
COMMENT=	XMPP/Jabber chat client written in Python/GTK3
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gettext

MANCOMPRESSED=	yes
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}

# needs --desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

DEPENDS+=	${PYPKGPREFIX}-certifi-[0-9]*:../../security/py-certifi
DEPENDS+=	${PYPKGPREFIX}-cssutils-[0-9]*:../../textproc/py-cssutils
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp-[0-9]*:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-precis-i18n-[0-9]*:../../textproc/py-precis-i18n

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
