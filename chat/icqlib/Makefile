# $NetBSD: Makefile,v 1.6 2004/01/22 07:49:20 grant Exp $

DISTNAME=		icqlib-1.0.0
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
