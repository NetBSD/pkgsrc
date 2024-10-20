# $NetBSD: Makefile,v 1.77 2024/10/20 14:03:28 wiz Exp $

DISTNAME=	gajim-1.3.3
PKGREVISION=	12
CATEGORIES=	chat
MASTER_SITES=	https://www.gajim.org/downloads/${PKGVERSION_NOREV:R}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gajim.org/
COMMENT=	XMPP/Jabber chat client written in Python/GTK3
LICENSE=	gnu-gpl-v3

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-cairo>=1.16.0:../../graphics/py-cairo
DEPENDS+=	${PYPKGPREFIX}-css-parser-[0-9]*:../../textproc/py-css-parser
DEPENDS+=	${PYPKGPREFIX}-keyring-[0-9]*:../../security/py-keyring
DEPENDS+=	${PYPKGPREFIX}-nbxmpp>=2.0.1:../../chat/py-nbxmpp
DEPENDS+=	${PYPKGPREFIX}-packaging-[0-9]*:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-precis-i18n-[0-9]*:../../textproc/py-precis-i18n

WRKSRC=		${WRKDIR}/gajim-gajim-${PKGVERSION_NOREV}

USE_TOOLS+=	gettext

MANCOMPRESSED=	yes
MAKE_ENV+=	PKGMANDIR=${PKGMANDIR}

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Cocoa-[0-9]*:../../devel/py-pyobjc-framework-Cocoa
.endif

.include "options.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/batteries-included.mk"
.include "../../lang/python/wheel.mk"
PYTHON_VERSIONED_DEPENDENCIES+=	OpenSSL
.include "../../lang/python/versioned_dependencies.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
