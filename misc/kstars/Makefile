# $NetBSD: Makefile,v 1.10 2004/01/03 18:49:47 reed Exp $
# FreeBSD Id: ports/astro/kstars/Makefile,v 1.7 2002/03/31 06:52:00 pat Exp

DISTNAME=	kstars-0.9.kde2
PKGBASE=	kstars-0.9
PKGNAME=	${PKGBASE}
PKGREVISION=	3
WRKSRC=		${WRKDIR}/${PKGBASE}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kstars/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://edu.kde.org/kstars/
COMMENT=	Desktop planetarium that presents the night sky at any date and time

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdelibs2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
