# $NetBSD: Makefile,v 1.13 2003/12/18 23:38:53 grant Exp $
#

DISTNAME=		xmms-mad-0.5.5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmms-mad/}

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

CPPFLAGS.NetBSD+=	-DHAVE_NANOSLEEP=1

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
