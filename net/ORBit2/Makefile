# $NetBSD: Makefile,v 1.1.1.1 2002/04/23 12:24:47 rh Exp $
#

DISTNAME=		ORBit2-2.3.108
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=pre-gnome2/sources/ORBit2/}/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		high-performance CORBA ORB with C language support

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

.include "../../net/linc/buildlink.mk"
.include "../../net/libIDL/buildlink.mk"
.include "../../devel/popt/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
