# $NetBSD: Makefile,v 1.25 2001/08/20 03:47:05 jlam Exp $

DISTNAME=		esound-0.2.22
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GNOME:=stable/sources/esound/}

MAINTAINER=		root@garbled.net
HOMEPAGE=		http://www.tux.org/~ricdude/EsounD.html
COMMENT=		the Enlightened sound daemon

GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_BUILDLINK_ONLY=	YES
REPLACE_BUILDLINK=	esd-config

.include "../../audio/libaudiofile/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
