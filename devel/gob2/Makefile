# $NetBSD: Makefile,v 1.1.1.1 2004/12/02 21:05:44 dillo Exp $
#

DISTNAME=	gob2-2.0.11
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
