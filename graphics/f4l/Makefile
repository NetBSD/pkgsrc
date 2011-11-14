# $NetBSD: Makefile,v 1.16 2011/11/14 14:37:19 dholland Exp $

DISTNAME=	f4l-0.2.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=f4l/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://f4l.sourceforge.net/
COMMENT=	Development environment for Macromedia Flash

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

NO_CONFIGURE=		yes
USE_LANGUAGES=		c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/f4l ${DESTDIR}${PREFIX}/bin

.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../x11/qt3-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
