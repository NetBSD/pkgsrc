# $NetBSD: Makefile,v 1.27 2001/10/03 22:36:37 jlam Exp $

DISTNAME=		esound-0.2.23
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
