# $NetBSD: Makefile,v 1.1.1.1 2003/06/02 11:04:19 jmmv Exp $
#

DISTNAME=		gini-0.5.1
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gini/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jrp@hispabsd.org
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
