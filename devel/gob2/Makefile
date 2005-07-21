# $NetBSD: Makefile,v 1.3 2005/07/21 16:29:47 wiz Exp $
#

DISTNAME=	gob2-2.0.11
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

GNU_CONFIGURE=	YES

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
