# $NetBSD: Makefile,v 1.15 2009/08/26 19:57:59 sno Exp $

DISTNAME=	qalculate-bases-0.9.4
PKGREVISION=	1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qalculate/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://qalculate.sourceforge.net/
COMMENT=	Utility for conversion between number bases using Qalculate

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes

.include "../../math/qalculate/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
