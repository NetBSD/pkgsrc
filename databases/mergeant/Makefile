# $NetBSD: Makefile,v 1.18 2004/02/14 17:21:35 jlam Exp $
#

DISTNAME=		mergeant-0.12.1
PKGREVISION=		8
CATEGORIES=		databases gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/mergeant/0.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 GNOME-DB database front-end

DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

USE_PERL5=              build
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
