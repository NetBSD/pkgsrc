# $NetBSD: Makefile,v 1.15 2005/12/05 20:49:50 rillig Exp $
#

DISTNAME=		xmms-FMRadio-1.4
PKGNAME=		xmms-fmradio-1.4
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		http://silicone.free.fr/xmms-FMRadio/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://silicone.free.fr/xmms-FMRadio/
COMMENT=		Use a Radio Tuner card in XMMS

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[A-Z]-* NetBSD-1.6*-* NetBSD-[2-9]*-*

BINOWN?=		${ROOT_USER}
BINGRP?=		${ROOT_GROUP}

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
