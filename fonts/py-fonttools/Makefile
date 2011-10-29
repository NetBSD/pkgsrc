# $NetBSD: Makefile,v 1.18 2011/10/29 11:40:27 obache Exp $
#

DISTNAME=		fonttools-2.3
PKGNAME=		${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=		fonts python
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=fonttools/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://fonttools.sourceforge.net/
COMMENT=		Library for manipulating fonts

DEPENDS+=	${PYPKGPREFIX}-numpy-[0-9]*:../../math/py-numpy
DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

PKG_DESTDIR_SUPPORT=	user-destdir

SUBST_CLASSES+=		fix-mandir
SUBST_STAGE.fix-mandir=	pre-configure
SUBST_FILES.fix-mandir=	setup.py
SUBST_SED.fix-mandir=	-e 's|share/man/man1|${PKGMANDIR}/man1|g'

.include "../../lang/python/distutils.mk"
.include "../../mk/bsd.pkg.mk"
