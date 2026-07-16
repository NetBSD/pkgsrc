# $NetBSD: Makefile,v 1.36 2026/07/16 19:04:17 wiz Exp $

DISTNAME=	beacon-1.3
PKGREVISION=	17
CATEGORIES=	mbone
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://dast.nlanr.net/Projects/Beacon/
COMMENT=	Multicast supervision tool
LICENSE=	modified-bsd

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples/beacon

USE_TOOLS+=	tar patch perl

PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		auto/Net/Multicast/Beacon/.packlist

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/beacon.in
SUBST_STAGE.conf=	pre-configure
SUBST_SED.conf=		-e s,@prefix@/etc,${PKG_SYSCONFDIR},

CONF_FILES+=	${PREFIX}/share/examples/beacon/beacon.conf \
		${PKG_SYSCONFDIR}/beacon.conf

post-extract:
	cd ${WRKSRC} && ${TAR} -zxvf common-1.2.16.tar.gz

pre-patch:
	cd ${WRKSRC} && ${PATCH} -p0 < common-beacon.patch

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
