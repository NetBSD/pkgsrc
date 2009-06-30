# $NetBSD: Makefile,v 1.14 2009/06/30 00:07:21 joerg Exp $
#

DISTNAME=		gini-0.5.1
PKGREVISION=		3
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gini/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://gini.sourceforge.net/
COMMENT=		Free streaming media server

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/glib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
