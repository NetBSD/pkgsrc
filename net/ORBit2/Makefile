# $NetBSD: Makefile,v 1.8 2002/10/05 03:34:20 wiz Exp $
#

DISTNAME=		ORBit2-2.4.0
PKGREVISION=		2
CATEGORIES=		net gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=2.0.0/sources/ORBit2/}/
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
