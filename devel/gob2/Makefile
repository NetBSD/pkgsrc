# $NetBSD: Makefile,v 1.5 2005/09/07 10:31:55 adam Exp $

DISTNAME=	gob2-2.0.12
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
