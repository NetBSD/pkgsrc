# $NetBSD: Makefile,v 1.15 2004/03/12 01:26:59 snj Exp $
#

DISTNAME=		xmms-mad-0.5.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmms-mad/}

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES

CPPFLAGS.NetBSD+=	-DHAVE_NANOSLEEP=1

BUILDLINK_DEPENDS.libmad=	libmad>=0.15.0bnb1

.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
