# $NetBSD: Makefile,v 1.10 2002/10/27 09:16:08 rh Exp $
#

DISTNAME=		ORBit2-2.5.0
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/ORBit2/2.5/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@netbsd.org
HOMEPAGE=		http://orbit-resource.sourceforge.net/
COMMENT=		high-performance CORBA ORB with C language support

USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../net/linc/buildlink2.mk"
.include "../../net/libIDL/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
