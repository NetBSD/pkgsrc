# $NetBSD: Makefile,v 1.16 1999/04/27 22:04:16 tron Exp $
#

DISTNAME=	ORBit-0.4.3
CATEGORIES=	corba
MASTER_SITES=	ftp://ftp.gnome.org/pub/GNOME/gnome-1.0/sources/ \
		ftp://ftp.jimpick.com/pub/mirrors/gnome/gnome-1.0/sources/ \
		ftp://ftp.informatik.uni-bonn.de/pub/os/unix/gnome/gnome-1.0/sources/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.gnome.org/

DEPENDS+=	glib-1.2.1:../../devel/glib
DEPENDS+=	gindent-1.9.1:../../devel/gindent

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes
CONFIGURE_ENV+=	INSTALL_SCRIPT="${INSTALL_SCRIPT}"

LIBTOOL_FLAGS=	--install-la
INFO_FILES=	libIDL.info

post-extract:
	@find ${WRKDIR} -name "*.idl" -type f | xargs ${TOUCH}

.include "../../mk/bsd.pkg.mk"
