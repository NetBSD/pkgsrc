# $NetBSD: Makefile,v 1.2 2004/05/22 05:51:17 sekiya Exp $

DISTNAME=		ifp-line-0.2.4
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://ifp-driver.sourceforge.net/
COMMENT=		Command-line interface to iRiver MP3 players

USE_BUILDLINK3=		YES

.include "../../mk/bsd.prefs.mk"

.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
