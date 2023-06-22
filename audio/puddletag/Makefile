# $NetBSD: Makefile,v 1.2 2023/06/22 11:23:48 jperkin Exp $

DISTNAME=	puddletag-2.0.1
CATEGORIES=	audio python
MASTER_SITES=	${MASTER_SITE_GITHUB:=puddletag/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
GITHUB_PROJECT=	puddletag

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://puddletag.sourceforge.net/
COMMENT=	Simple, powerful audio tag editor
LICENSE=	gnu-gpl-v2

DEPENDS+=	chromaprint>=0.4:../../audio/chromaprint
DEPENDS+=	quodlibet-[0-9]*:../../audio/quodlibet
DEPENDS+=	${PYPKGPREFIX}-configobj-[0-9]*:../../devel/py-configobj
DEPENDS+=	${PYPKGPREFIX}-pyparsing>=1.5.1:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-mutagen>=1.45:../../audio/py-mutagen
DEPENDS+=	${PYPKGPREFIX}-qt5-[0-9]*:../../x11/py-qt5

USE_LANGUAGES=	# none

PYTHON_SELF_CONFLICT=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	27 37

INSTALLATION_DIRS=	${PKGMANDIR}/man1

post-install:
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/* ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
