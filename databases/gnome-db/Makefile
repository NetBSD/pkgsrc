# $NetBSD: Makefile,v 1.1.1.1 2002/10/30 06:44:59 rh Exp $
#

DISTNAME=		gnome-db-0.8.192
CATEGORIES=		database gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-db/0.8/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		sab@posix.org.uk
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 database applications and libraries

USE_PERL5=		build
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
