# $NetBSD: Makefile,v 1.14 2004/02/01 10:59:26 jmmv Exp $
#

DISTNAME=		xmms-mad-0.5.5
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmms-mad/}

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

CPPFLAGS.NetBSD+=	-DHAVE_NANOSLEEP=1

BUILDLINK_DEPENDS.libmad=	libmad>=0.15.0bnb1

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
