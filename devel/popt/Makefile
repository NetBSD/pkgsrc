# $NetBSD: Makefile,v 1.16 2002/11/30 23:21:39 salo Exp $
#

DISTNAME=	popt-1.7
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/		\
		http://gd.tuwien.ac.at/z7/utils/rpm.org/dist/rpm-4.1.x/	\
		ftp://ftp.iks-jena.de/pub/software/unix/misc/		\
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/rpm-4.1.x/

MAINTAINER=	packages@netbsd.org
COMMENT=	Command line option parsing library

BUILD_USES_MSGFMT=	yes

CONFLICTS=		ORBit<=0.5.3

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_GMAKE=		yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

WRKSRC=			${WRKDIR}/${DISTNAME}

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
