# $NetBSD: Makefile,v 1.5 2004/02/14 17:21:46 jlam Exp $
#

DISTNAME=		gini-0.5.1
PKGREVISION=		1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gini/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://gini.sourceforge.net/
COMMENT=		Free streaming media server

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
