# $NetBSD: Makefile,v 1.1.1.1 2003/07/21 09:56:35 wiz Exp $
#

DISTNAME=		libggigcp-0.8.2.src
PKGNAME=		${DISTNAME:S/.src//}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			ftp://ftp.ggi-project.org/pub/ggi/extensions/libgcp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggigcp.html
COMMENT=		Color management extension for GGI

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggigcp
CONF_FILES=		${EGDIR}/libggigcp.conf ${PKG_SYSCONFDIR}/libggigcp.conf

.include "../../graphics/libggi/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
