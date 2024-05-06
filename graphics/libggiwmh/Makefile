# $NetBSD: Makefile,v 1.20 2024/05/06 08:40:27 jperkin Exp $
#

DISTNAME=		libggiwmh-0.3.2.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		2
CATEGORIES=		graphics devel
#MASTER_SITES=		http://www.ggi-project.org/ftp/ggi/v2.2/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ggi-project.org/packages/libggiwmh.html
HOMEPAGE=		https://ibiblio.org/ggicore/
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
