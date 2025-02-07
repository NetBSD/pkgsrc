# $NetBSD: Makefile,v 1.81 2025/02/07 21:47:41 adam Exp $

DISTNAME=	gajim-1.9.5
CATEGORIES=	chat
MASTER_SITES=	https://www.gajim.org/downloads/${PKGVERSION_NOREV:R}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gajim.org/
COMMENT=	XMPP/Jabber chat client written in Python/GTK3
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-Pillow>=9.1.0:../../graphics/py-Pillow
DEPENDS+=	${PYPKGPREFIX}-cairo>=1.16.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-emoji>=2.6.0:../../converters/py-emoji
DEPENDS+=	${PYPKGPREFIX}-gobject3>=3.42.0:../../devel/py-gobject3
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp>=5.0.4:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-omemo-dr>=1.0.0:../../security/py-omemo-dr
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-precis-i18n>=1.0.0:../../textproc/py-precis-i18n
DEPENDS+=	${PYPKGPREFIX}-qrcode>=7.3.1:../../graphics/py-qrcode
DEPENDS+=	${PYPKGPREFIX}-sqlalchemy>=2.0.0:../../databases/py-sqlalchemy

USE_TOOLS+=	gettext

PYTHON_VERSIONS_INCOMPATIBLE=	39	# py-omemo-dr

MANCOMPRESSED=	yes

SUBST_CLASSES+=		manpath
SUBST_STAGE.manpath=	pre-configure
SUBST_MESSAGE.manpath=	Fixing man path.
SUBST_FILES.manpath=	make.py
SUBST_SED.manpath=	-e 's,share/man,${PKGMANDIR},'

#.include "../../mk/bsd.prefs.mk"

#.if ${OPSYS} == "Darwin"
#DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
#.endif

.include "options.mk"

.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL cryptography
.include "../../lang/python/versioned_dependencies.mk"
.include "../../x11/gtksourceview4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
