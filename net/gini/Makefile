# $NetBSD: Makefile,v 1.2 2003/08/28 20:05:20 xtraeme Exp $
#

DISTNAME=		gini-0.5.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gini/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		xtraeme@NetBSD.org
HOMEPAGE=		http://gini.sourceforge.net/
COMMENT=		Free streaming media server

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=       ${WRKSRC}/libtool

.include "../../audio/libvorbis/buildlink2.mk"
.include "../../devel/glib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
