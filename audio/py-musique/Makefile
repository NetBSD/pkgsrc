# $NetBSD: Makefile,v 1.9 2006/09/03 00:56:28 wiz Exp $
#

DISTNAME=	pymusique-0.5
PKGNAME=        ${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	http://fuware.nanocrew.net/pymusique/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fuware.nanocrew.net/pymusique/
COMMENT=	Interface to the iTunes Music Store

RESTRICTED=	Possible legal problems due to iTuness access
NO_SRC_ON_FTP=          ${RESTRICTED}
NO_BIN_ON_FTP=          ${RESTRICTED}
NO_SRC_ON_CDROM=        ${RESTRICTED}
NO_BIN_ON_CDROM=        ${RESTRICTED}

DEPENDS+=	${PYPKGPREFIX}-twisted-[0-9]*:../../net/py-twisted
DEPENDS+=	${PYPKGPREFIX}-OpenSSL-[0-9]*:../../security/py-OpenSSL
DEPENDS+=	${PYPKGPREFIX}-mcrypt-[0-9]*:../../security/py-mcrypt
DEPENDS+=	${PYPKGPREFIX}-libxml2-[0-9]*:../../textproc/py-libxml2
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PYTHON_VERSIONS_ACCEPTED=	24 23

PYDISTUTILSPKG= yes

.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
