# $NetBSD: Makefile,v 1.74 2022/04/18 19:10:25 adam Exp $

DISTNAME=	pymusique-0.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	45
CATEGORIES=	audio
#MASTER_SITES=	http://www.pyronecrophilia.com/content/pymusique/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.pyronecrophilia.com/content/pymusique/
COMMENT=	Interface to the iTunes Music Store

RESTRICTED=		Possible legal problems due to iTunes access
NO_SRC_ON_FTP=		${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_CDROM=	${RESTRICTED}

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted19
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-mcrypt-[0-9]*:../../security/py-mcrypt
DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_VERSIONS_ACCEPTED=	27 # py-mcrypt, py-gtk2
EGG_NAME=			PyMusique-${PKGVERSION_NOREV}

.include "../../lang/python/egg.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
