# $NetBSD: Makefile,v 1.1.1.1 2002/06/19 11:20:02 agc Exp $
# FreeBSD Id: ports/astro/kstars/Makefile,v 1.7 2002/03/31 06:52:00 pat Exp

DISTNAME=	kstars-0.9.kde2
PKGNAME=	kstars-0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kstars/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://edu.kde.org/kstars/
COMMENT=	Desktop planetarium that presents the night sky at any date and time

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_LIBTOOL=	yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../graphics/jpeg/buildlink.mk"
.include "../../x11/kde2/buildlink.mk"
.include "../../x11/kdelibs2/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
