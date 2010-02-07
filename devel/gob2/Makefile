# $NetBSD: Makefile,v 1.13 2010/02/07 18:06:09 zafer Exp $

DISTNAME=	gob2-2.0.16
CATEGORIES=	devel gnome
MASTER_SITES=	http://ftp.5z.com/pub/gob/

MAINTAINER=	dillo@NetBSD.org
HOMEPAGE=	http://www.5z.com/jirka/gob.html
COMMENT=	GNOME object builder for glib2
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		lex pkg-config
GNU_CONFIGURE=		yes

.include "../../mk/bsd.prefs.mk"

LIBS+=	-lfl

.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
