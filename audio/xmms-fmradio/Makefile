# $NetBSD: Makefile,v 1.19 2006/11/05 14:47:55 rillig Exp $
#

DISTNAME=		xmms-FMRadio-1.4
PKGNAME=		xmms-fmradio-1.4
PKGREVISION=		4
CATEGORIES=		audio
MASTER_SITES=		http://silicone.free.fr/xmms-FMRadio/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://silicone.free.fr/xmms-FMRadio/
COMMENT=		Use a Radio Tuner card in XMMS

ONLY_FOR_PLATFORM=	NetBSD-1.5Z[A-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

MAKE_ENV+=		${BSD_MAKE_ENV}

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
