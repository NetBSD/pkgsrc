# $NetBSD: Makefile,v 1.17 2026/08/03 13:12:30 wiz Exp $

DISTNAME=	less-382
PKGNAME=	ja-${DISTNAME}.262.03
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_GNU:=less/}

PATCH_SITES=		http://ryo-on.users.sourceforge.net/distrib/ja-less/
PATCHFILES=		less-382-iso258.patch.gz
PATCHFILES+=		less-382-iso258-259.patch.gz
PATCHFILES+=		less-382-iso259-260.patch.gz
PATCHFILES+=		less-382-iso260-261.patch.gz
PATCHFILES+=		less-382-iso261-262.patch.gz
PATCHFILES+=		less-382-iso262.ext03.patch.gz

MAINTAINER=	komine@cc.meisei-u.ac.jp
# HOMEPAGE is gone.
#HOMEPAGE=	http://www25.big.jp/~jam/less/
COMMENT=	Less + zcat + ISO-2022 + UTF-8 - a pager similar to more and pg

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	post-configure
SUBST_FILES.cfgdir=	less.nro
SUBST_SED.cfgdir=	-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|'

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
