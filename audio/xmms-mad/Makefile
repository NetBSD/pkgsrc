# $NetBSD: Makefile,v 1.12 2003/12/17 03:27:17 simonb Exp $
#

DISTNAME=		xmms-mad-0.5.5
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmms-mad/}

MAINTAINER=		jmcneill@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=              -DHAVE_NANOSLEEP=1
.endif

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../audio/libid3tag/buildlink2.mk"
.include "../../audio/libmad/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
