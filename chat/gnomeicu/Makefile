# $NetBSD: Makefile,v 1.3 2001/06/11 06:34:21 jlam Exp $

DISTNAME=	gnomeicu-0.96
CATEGORIES=	chat gnome
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gnomeicu/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://gnomeicu.sourceforge.net/
COMMENT=	GNOME ICQ client

DEPENDS+=	gdbm>=1.8.0:../../databases/gdbm
DEPENDS+=	gnome-core>=1.2.0:../../x11/gnome-core
DEPENDS+=	libiconv>=1.5:../../converters/libiconv

GNU_CONFIGURE=	YES
USE_X11BASE=	YES
USE_GMAKE=	YES
USE_LIBINTL=	YES

CPPFLAGS+=	-I${LOCALBASE}/include
LIBS+=		-liconv

.include "../../mk/bsd.pkg.mk"
