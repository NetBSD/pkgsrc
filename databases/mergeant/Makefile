# $NetBSD: Makefile,v 1.1.1.1 2003/02/21 11:58:55 salo Exp $
#

DISTNAME=		mergeant-0.10.0
CATEGORIES=		database gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-db/0.10.0/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.gnome-db.org/
COMMENT=		GNOME2 GNOME-DB database front-end

USE_PERL5=              build
USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_PKGLOCALEDIR=	YES
GNU_CONFIGURE=		YES
USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../databases/libgnomedb/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
