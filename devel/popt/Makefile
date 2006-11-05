# $NetBSD: Makefile,v 1.34 2006/11/05 17:49:34 joerg Exp $
#

DISTNAME=	popt-1.7
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.rpm.org/pub/rpm/dist/rpm-4.1.x/		\
		ftp://ftp.iks-jena.de/pub/software/unix/misc/		\
		ftp://sunsite.cnlab-switch.ch/mirror/rpm/dist/rpm-4.1.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Command line option parsing library

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		ORBit<=0.5.3

WRKSRC=			${WRKDIR}/${DISTNAME}
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake msgfmt
USE_LIBTOOL=		yes

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
