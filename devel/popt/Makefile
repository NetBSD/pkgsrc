# $NetBSD: Makefile,v 1.25 2004/01/20 12:13:29 agc Exp $
#

DISTNAME=	popt-1.7
PKGREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/		\
		ftp://ftp.iks-jena.de/pub/software/unix/misc/		\
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/rpm-4.1.x/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Command line option parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews

CONFLICTS=		ORBit<=0.5.3

BUILD_USES_MSGFMT=	yes

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
