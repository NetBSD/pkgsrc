# $NetBSD: Makefile,v 1.2 2024/02/19 15:11:42 schmonz Exp $

DISTNAME=	dkimpy-1.1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	mail python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dkimpy/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/dkimpy/
COMMENT=	DKIM, ARC, and TLSRPT email signing and verification
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-aiodns-[0-9]*:../../net/py-aiodns
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

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
