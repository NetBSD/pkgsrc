# $NetBSD: Makefile,v 1.2 2002/01/14 15:28:38 wiz Exp $
#

DISTNAME=		xmms-FMRadio-1.4
PKGNAME=		xmms-fmradio-1.4
CATEGORIES=		audio
MASTER_SITES=		http://silicone.free.fr/xmms-FMRadio/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://silicone.free.fr/xmms-FMRadio/
COMMENT=		Use a Radio Tuner card in XMMS

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[A-Z]-*-* NetBSD-1.[6-9]*-*

USE_BUILDLINK_ONLY=	YES
BINOWN?=		root
BINGRP?=		wheel

.include "../../audio/xmms/buildlink.mk"
.include "../../mk/ossaudio.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
