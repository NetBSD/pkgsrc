# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:55 tv Exp $
#

DISTNAME=		libggigcp-0.8.2.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			ftp://ftp.ggi-project.org/pub/ggi/extensions/libgcp/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggigcp.html
COMMENT=		Color management extension for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggigcp
CONF_FILES=		${EGDIR}/libggigcp.conf ${PKG_SYSCONFDIR}/libggigcp.conf

.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
