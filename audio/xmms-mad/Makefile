# $NetBSD: Makefile,v 1.5 2002/10/17 00:06:47 jlam Exp $
#

DISTNAME=		xmms-mad-0.0.9
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		http://www.superduper.net/downloads/xmms-mad/

MAINTAINER=		jmcneill@netbsd.org
HOMEPAGE=		http://www.superduper.net/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad


GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES

.include "../../mk/bsd.prefs.mk"

.if (${OPSYS} == NetBSD)
CPPFLAGS+=              -DHAVE_NANOSLEEP=1
.endif

.include "../../audio/mad/buildlink2.mk"
.include "../../audio/xmms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
