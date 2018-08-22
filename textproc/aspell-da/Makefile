# $NetBSD: Makefile,v 1.8 2018/08/22 09:46:44 wiz Exp $

DISTNAME=	aspell-da-1.7.42
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	http://da.speling.org/filer/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://da.speling.org/
COMMENT=	Danish language support for aspell
LICENSE=	gnu-gpl-v2

CONFLICTS+=	aspell-danish-[0-9]*
USE_TOOLS+=	perl
REPLACE_PERL=	unsq

INSTALLATION_DIRS+=	lib/aspell share/aspell

SUBST_CLASSES+=			avoid_patch
SUBST_MESSAGE.avoid_patch=	Adjust before patch to absorb versioning (or avoid manual edit)
SUBST_FILES.avoid_patch+=	Makefile
SUBST_STAGE.avoid_patch=	pre-patch
SUBST_SED.avoid_patch+=		-e 's/${PKGVERSION_NOREV}/@@PKGVERSION_NOREV@@/'

.include "../../textproc/aspell/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
