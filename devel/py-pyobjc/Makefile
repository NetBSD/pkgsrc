# $NetBSD: Makefile,v 1.1 2015/04/25 10:40:48 adam Exp $

META_PACKAGE=	yes

.include "Makefile.common"

PKGNAME=	${PYPKGPREFIX}-pyobjc-${PYOBJC_VERS}
CATEGORIES+=	meta-pkgs
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pythonhosted.org/pyobjc/
COMMENT=	Bridge between Python and Objective-C
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-pyobjc-core>=${PYOBJC_VERS}:../../devel/py-pyobjc-core
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Accounts>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Accounts
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AddressBook>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AddressBook
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AppleScriptKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AppleScriptKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-AppleScriptObjC>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-AppleScriptObjC
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Automator>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Automator
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CalendarStore>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CalendarStore
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CFNetwork>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CFNetwork
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Collaboration>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Collaboration
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreData>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreData
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreLocation>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreLocation
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreText>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreText
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-CoreWLAN>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-CoreWLAN
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-DictionaryServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-DictionaryServices
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-DiskArbitration>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-DiskArbitration
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-EventKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-EventKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-ExceptionHandling>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-ExceptionHandling
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-FSEvents>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-FSEvents
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-InputMethodKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-InputMethodKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-InstallerPlugins>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-InstallerPlugins
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-InstantMessage>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-InstantMessage
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-LatentSemanticMapping>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-LatentSemanticMapping
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-LaunchServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-LaunchServices
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-OpenDirectory>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-OpenDirectory
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-PreferencePanes>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-PreferencePanes
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-PubSub>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-PubSub
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-QTKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-QTKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-ScreenSaver>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-ScreenSaver
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-ScriptingBridge>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-ScriptingBridge
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SearchKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SearchKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-ServiceManagement>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-ServiceManagement
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-Social>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-Social
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-StoreKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-StoreKit
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SyncServices>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SyncServices
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-SystemConfiguration>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-SystemConfiguration
DEPENDS+=	${PYPKGPREFIX}-pyobjc-framework-WebKit>=${PYOBJC_VERS}:../../devel/py-pyobjc-framework-WebKit

.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
