# $NetBSD: Makefile,v 1.12 2009/11/01 22:24:58 joerg Exp $

DISTNAME=	gob2-2.0.16
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/ \
		http://ftp.5z.com/pub/gob/old/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		lex pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

LIBS+=	-lfl

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
