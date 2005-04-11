# $NetBSD: Makefile,v 1.13 2005/04/11 21:44:58 tv Exp $
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

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[A-Z]-*-* NetBSD-1.6*-* NetBSD-[2-9]*-*

USE_X11=		YES
BINOWN?=		${ROOT_USER}
BINGRP?=		${ROOT_GROUP}

.include "../../audio/xmms/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
