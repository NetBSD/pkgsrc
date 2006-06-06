# $NetBSD: Makefile,v 1.11 2006/06/06 14:38:31 joerg Exp $

DISTNAME=		icqlib-1.0.0
PKGREVISION=		3
CATEGORIES=		chat
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=icqlib/}

MAINTAINER=		magick@NetBSD.org
HOMEPAGE=		http://kicq.sourceforge.net/icqlib.shtml
COMMENT=		Implementation of the icq protocol

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

.include "../../mk/bsd.pkg.mk"
