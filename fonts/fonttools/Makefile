# $NetBSD: Makefile,v 1.1 2017/10/02 22:08:05 khorben Exp $

DISTNAME=	fonttools-3.15.1
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=fonttools/}

MAINTAINER=	khorben@defora.org
HOMEPAGE=	https://groups.google.com/forum/#!forum/fonttools
COMMENT=	Library to manipulate font files from Python
LICENSE=	modified-bsd

SUBST_CLASSES+=		pkgmandir
SUBST_MESSAGE.pkgmandir=Fixing path to manual pages.
SUBST_STAGE.pkgmandir=	post-patch
SUBST_SED.pkgmandir=	-e 's,@PKGMANDIR@,${PKGMANDIR},g'
SUBST_FILES.pkgmandir=	setup.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
