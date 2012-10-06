# $NetBSD: Makefile,v 1.16 2012/10/06 14:11:04 asau Exp $
#

DISTNAME=		libggiwmh-0.3.2.src
PKGNAME=		${DISTNAME:S/.src//}
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			http://www.ggi-project.org/ftp/ggi/v2.2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggiwmh.html
COMMENT=		Windows Manager hints library for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggiwmh
CONF_FILES=		${EGDIR}/libggiwmh.conf ${PKG_SYSCONFDIR}/libggiwmh.conf

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../graphics/libggi/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
