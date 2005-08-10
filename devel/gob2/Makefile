# $NetBSD: Makefile,v 1.4 2005/08/10 20:56:15 jlam Exp $
#

DISTNAME=	gob2-2.0.11
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

GNU_CONFIGURE=	YES
USE_TOOLS+=	pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
