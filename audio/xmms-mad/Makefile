# $NetBSD: Makefile,v 1.26 2011/04/22 13:43:01 obache Exp $
#

DISTNAME=		xmms-mad-0.5.7
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=xmms-mad/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://sourceforge.net/projects/xmms-mad/
COMMENT=		Input plugin for XMMS that uses libmad

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		YES
USE_TOOLS+=		pkg-config

CPPFLAGS.NetBSD+=	-DHAVE_NANOSLEEP=1

BUILDLINK_API_DEPENDS.libmad+=	libmad>=0.15.0bnb1

.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/xmms/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
