# $NetBSD: Makefile,v 1.54 2020/07/08 11:57:12 adam Exp $

DISTNAME=	gajim-1.2.0
CATEGORIES=	chat python
MASTER_SITES=	https://www.gajim.org/downloads/${PKGVERSION_NOREV:R}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gajim.org/
COMMENT=	XMPP/Jabber chat client written in Python/GTK3
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	gettext

MANCOMPRESSED=	yes
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}

# needs --desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27 36

DEPENDS+=	${PYPKGPREFIX}-cairo>=1.16.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp-[0-9]*:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-precis-i18n-[0-9]*:../../textproc/py-precis-i18n
DEPENDS+=	${PYPKGPREFIX}-sqlite3-[0-9]*:../../databases/py-sqlite3

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
.endif

SUBST_CLASSES+=		paths
SUBST_STAGE.paths=	pre-configure
SUBST_MESSAGE.paths=	Fixing absolute paths.
SUBST_FILES.paths=	gajim/common/i18n.py
SUBST_SED.paths=        -e 's,/usr/local,${PREFIX},g'

.include "options.mk"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/egg.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
