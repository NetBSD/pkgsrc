# $NetBSD: Makefile,v 1.9 1999/01/16 12:05:09 tron Exp $
#

DISTNAME=	ORBit-0.3.90
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/ORBit/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.1.12:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

CONFLICTS=	ORBit-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

.include "../../mk/bsd.pkg.mk"
