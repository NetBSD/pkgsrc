# $NetBSD: Makefile,v 1.5 2006/05/19 18:11:59 abs Exp $
#

DISTNAME=		mpeg4ip-1.4.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

CONFLICTS+=		faad2-[0-9]*

USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap
LIBTOOL_OVERRIDE=	libtool */libtool */*/libtool */*/*/libtool

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
