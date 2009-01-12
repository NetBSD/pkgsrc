# $NetBSD: Makefile,v 1.20 2009/01/12 16:21:38 jmcneill Exp $
#

DISTNAME=		xmms-FMRadio-1.4
PKGNAME=		xmms-fmradio-1.4
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://silicone.free.fr/xmms-FMRadio/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://silicone.free.fr/xmms-FMRadio/
COMMENT=		Use a Radio Tuner card in XMMS

ONLY_FOR_PLATFORM=	NetBSD-1.5Z[A-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

MAKE_ENV+=		${BSD_MAKE_ENV}

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
