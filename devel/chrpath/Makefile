# $NetBSD: Makefile,v 1.1.1.1 2008/02/28 23:38:10 tnn Exp $
#

DISTNAME=	chrpath-0.13
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.hungry.com/pub/hungry/chrpath/ \
		${MASTER_SITE_GENTOO:=distfiles/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://freshmeat.net/projects/chrpath/
COMMENT=	Change the dynamic library load path of compiled binaries

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../mk/bsd.pkg.mk"
