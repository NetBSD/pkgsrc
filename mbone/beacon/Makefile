# $NetBSD: Makefile,v 1.1.1.1 2005/02/03 15:06:36 cube Exp $
#

DISTNAME=	beacon-1.1-0
PKGNAME=	beacon-1.1.0
CATEGORIES=	mbone
MASTER_SITES=	http://dast.nlanr.net/Projects/Beacon/releases/

MAINTAINER=	manu@NetBSD.org
HOMEPAGE=	http://dast.nlanr.net/Projects/Beacon/
COMMENT=	Multicast supervison tool

GNU_CONFIGURE=	YES
USE_BUILDLINK3=	YES
USE_PKGINSTALL=	YES
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples/beacon

PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Net/Multicast/Beacon/.packlist

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/beacon.in
SUBST_STAGE.conf=	post-patch
SUBST_SED.conf=		-e s,@prefix@/etc,${PKG_SYSCONFDIR},

CONF_FILES+=	${PREFIX}/share/examples/beacon/beacon.conf \
		${PKG_SYSCONFDIR}/beacon.conf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
