# $NetBSD: Makefile,v 1.12 2009/05/21 11:25:12 zafer Exp $
#

DISTNAME=	beacon-1.1-0
PKGNAME=	beacon-1.1.0
PKGREVISION=	4
CATEGORIES=	mbone
MASTER_SITES=	${MASTER_SITE_FREEBSD}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://dast.nlanr.net/Projects/Beacon/
COMMENT=	Multicast supervision tool

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+=	--sysconfdir=${PREFIX}/share/examples/beacon

USE_TOOLS+=	perl

PERL5_CONFIGURE=	NO
PERL5_PACKLIST=		auto/Net/Multicast/Beacon/.packlist

SUBST_CLASSES+=		conf
SUBST_FILES.conf=	src/beacon.in
SUBST_STAGE.conf=	post-patch
SUBST_SED.conf=		-e s,@prefix@/etc,${PKG_SYSCONFDIR},

CONF_FILES+=	${PREFIX}/share/examples/beacon/beacon.conf \
		${PKG_SYSCONFDIR}/beacon.conf

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
