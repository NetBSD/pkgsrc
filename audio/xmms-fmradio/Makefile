# $NetBSD: Makefile,v 1.6 2003/05/05 19:05:07 jmmv Exp $
#

DISTNAME=		xmms-FMRadio-1.4
PKGNAME=		xmms-fmradio-1.4
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://silicone.free.fr/xmms-FMRadio/
EXTRACT_SUFX=		.tgz

MAINTAINER=		jmcneill@invisible.yi.org
HOMEPAGE=		http://silicone.free.fr/xmms-FMRadio/
COMMENT=		Use a Radio Tuner card in XMMS

ONLY_FOR_PLATFORM=      NetBSD-1.5Z[A-Z]-*-* NetBSD-1.[6-9]*-*

USE_BUILDLINK2=		YES
USE_X11=		YES
BINOWN?=		${ROOT_USER}
BINGRP?=		${ROOT_GROUP}

.include "../../audio/xmms/buildlink2.mk"
.include "../../mk/ossaudio.buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
