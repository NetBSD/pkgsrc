# $NetBSD: Makefile,v 1.7 2004/10/03 00:13:14 tv Exp $

DISTNAME=		icqlib-1.0.0
PKGREVISION=		1
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=icqlib/}

MAINTAINER=		magick@NetBSD.org
HOMEPAGE=		http://kicq.sourceforge.net/icqlib.shtml
COMMENT=		Implementation of the icq protocol

USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
