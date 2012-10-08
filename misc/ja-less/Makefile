# $NetBSD: Makefile,v 1.11 2012/10/08 09:57:24 asau Exp $

DISTNAME=	less-382
PKGNAME=	ja-${DISTNAME}.262
PKGREVISION=	1
CATEGORIES=	japanese misc
MASTER_SITES=	${MASTER_SITE_GNU:=less/}

PATCH_SITES=	http://www25.big.jp/~jam/less/
PATCHFILES=	less-382-iso258.patch.gz
PATCHFILES+=	less-382-iso258-259.patch.gz
PATCHFILES+=	less-382-iso259-260.patch.gz
PATCHFILES+=	less-382-iso260-261.patch.gz
PATCHFILES+=	less-382-iso261-262.patch.gz
PATCH_DIST_STRIP= -p1

MAINTAINER=	komine@cc.meisei-u.ac.jp
HOMEPAGE=	http://www25.big.jp/~jam/less/
COMMENT=	Less + zcat + ISO-2022 - a pager similar to more and pg

GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}

SUBST_CLASSES+=		cfgdir
SUBST_STAGE.cfgdir=	post-configure
SUBST_FILES.cfgdir=	less.nro lesskey.nro
SUBST_SED.cfgdir=	-e 's|/usr/local/etc|${PKG_SYSCONFDIR}|'

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
