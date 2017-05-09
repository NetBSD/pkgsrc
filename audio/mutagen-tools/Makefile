# $NetBSD: Makefile,v 1.10 2017/05/09 13:14:32 leot Exp $

DISTNAME=	mutagen-1.37
PKGNAME=	${DISTNAME:S/-/-tools-/}
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mutagen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quodlibet/mutagen
COMMENT=	Audio metadata handling for Python
LICENSE=	gnu-gpl-v2

DEPENDS+=	${PYPKGPREFIX}-mutagen-[0-9]*:../../audio/py-mutagen

SUBST_CLASSES+=			pkgmandir
SUBST_STAGE.pkgmandir=		pre-configure
SUBST_FILES.pkgmandir=		setup.py
SUBST_MESSAGE.pkgmandir=	Fixing man page installation.
SUBST_SED.pkgmandir=		-e 's,share/man,${PKGMANDIR},'

USE_LANGUAGES=	# none
PY_NO_EGG=	yes

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
