# $NetBSD: Makefile,v 1.2 2002/09/20 12:05:19 jlam Exp $
# FreeBSD Id: ports/astro/kstars/Makefile,v 1.7 2002/03/31 06:52:00 pat Exp

DISTNAME=	kstars-0.9.kde2
PKGNAME=	kstars-0.9
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=kstars/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://edu.kde.org/kstars/
COMMENT=	Desktop planetarium that presents the night sky at any date and time

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined
USE_GMAKE=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

WRKSRC=		${WRKDIR}/${PKGNAME}

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../x11/kde2/buildlink2.mk"
.include "../../x11/kdelibs2/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
