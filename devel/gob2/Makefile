# $NetBSD: Makefile,v 1.6 2006/02/05 23:08:43 joerg Exp $

DISTNAME=	gob2-2.0.12
PKGREVISION=	1
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
