# $NetBSD: Makefile,v 1.10 2009/01/20 22:31:52 drochner Exp $

DISTNAME=	gob2-2.0.15
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		lex pkg-config
GNU_CONFIGURE=		yes

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
