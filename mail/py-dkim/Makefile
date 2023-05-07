# $NetBSD: Makefile,v 1.1 2023/05/07 20:37:52 markd Exp $

DISTNAME=	dkimpy-1.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dkimpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/dkimpy/
COMMENT=	DKIM, ARC, and TLSRPT email signing and verification
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-authres>=1.2.0:../../mail/py-authres
DEPENDS+=	${PYPKGPREFIX}-dns-[0-9]*:../../net/py-dns
DEPENDS+=	${PYPKGPREFIX}-nacl-[0-9]*:../../security/py-nacl

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.prefs.mk"

post-install:
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
