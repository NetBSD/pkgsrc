# $NetBSD: Makefile,v 1.4 2003/02/20 23:57:40 salo Exp $
#

DISTNAME=		gnome-db-0.8.192
PKGREVISION=		1
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
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BROKEN=			Does not compile anymore with recent libgnomedb. Obsoleted by mergeant.

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
