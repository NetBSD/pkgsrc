# $NetBSD: Makefile,v 1.23 2003/11/24 19:13:19 gson Exp $
#

DISTNAME=	popt-1.7
PKGREVISION=	4
WRKSRC=		${WRKDIR}/${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/		\
		ftp://ftp.iks-jena.de/pub/software/unix/misc/		\
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/rpm-4.1.x/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Command line option parsing library

BUILD_USES_MSGFMT=	yes

CONFLICTS=		ORBit<=0.5.3

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
