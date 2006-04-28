# $NetBSD: Makefile,v 1.2 2006/04/28 10:02:41 joerg Exp $
#

DISTNAME=		mpeg4ip-1.4.1
CATEGORIES=		multimedia
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=mpeg4ip/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://mpeg4ip.sourceforge.net/
COMMENT=		Tools for streaming video and audio

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_SCRIPT=	bootstrap
LIBTOOL_OVERRIDE=	libtool */libtool */*/libtool */*/*/libtool

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
