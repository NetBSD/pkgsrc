# $NetBSD: Makefile,v 1.24 2011/04/22 13:43:53 obache Exp $
#

DISTNAME=	grig-0.7.2
PKGREVISION=	6
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=groundstation/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://groundstation.sourceforge.net/
COMMENT=	Graphical user interface to the Hamlib libraries

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config
GNU_CONFIGURE=	yes

.include "../../ham/hamlib/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
