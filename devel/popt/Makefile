# $NetBSD: Makefile,v 1.9 2001/09/30 21:03:22 rh Exp $
#

DISTNAME=	popt-1.6.2
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.0.x/		\
		http://gd.tuwien.ac.at/z7/utils/rpm.org/dist/rpm-4.0.x/	\
		ftp://ftp.iks-jena.de/pub/software/unix/misc/		\
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/rpm-4.0.x/

MAINTAINER=	packages@netbsd.org
COMMENT=	Command line option parsing library

BUILD_USES_MSGFMT=	yes

CONFLICTS=	ORBit<=0.5.3

GNU_CONFIGURE=	yes
USE_GMAKE=	yes

WRKSRC=		${WRKDIR}/${PKGNAME}
CONFIGURE_ENV+=	PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
