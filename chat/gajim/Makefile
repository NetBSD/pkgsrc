# $NetBSD: Makefile,v 1.43 2018/11/14 22:21:08 kleink Exp $

DISTNAME=	gajim-1.0.3
PKGREVISION=	4
CATEGORIES=	chat python
MASTER_SITES=	https://www.gajim.org/downloads/1.0/

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

DEPENDS+=	${PYPKGPREFIX}-asn1-[0-9]*:../../security/py-asn1
DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp-[0-9]*:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna

.include "options.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
