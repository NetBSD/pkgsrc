# $NetBSD: Makefile,v 1.18 2020/08/16 22:38:55 tnn Exp $
#

DISTNAME=		libggigcp-1.0.2.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/}
#MASTER_SITES+=		http://www.ggi-project.org/ftp/ggi/v2.2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ggi-project.org/packages/libggigcp.html
HOMEPAGE=		https://ibiblio.org/ggicore/
COMMENT=		Color management extension for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggigcp
CONF_FILES=		${EGDIR}/libggigcp.conf ${PKG_SYSCONFDIR}/libggigcp.conf

.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
