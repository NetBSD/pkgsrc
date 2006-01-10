# $NetBSD: Makefile,v 1.9 2006/01/10 12:52:45 joerg Exp $

DISTNAME=		icqlib-1.0.0
PKGREVISION=		2
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=icqlib/}

MAINTAINER=		magick@NetBSD.org
HOMEPAGE=		http://kicq.sourceforge.net/icqlib.shtml
COMMENT=		Implementation of the icq protocol

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
