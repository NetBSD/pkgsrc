# $NetBSD: Makefile,v 1.1.1.1 2003/07/21 12:27:50 wiz Exp $
#

DISTNAME=		libggiwmh-0.1.0.src
PKGNAME=		${DISTNAME:S/.src//}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			ftp://ftp.ggi-project.org/pub/ggi/extensions/libwmh/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggiwmh.html
COMMENT=		Windows Manager hints library for GGI

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggiwmh
CONF_FILES=		${EGDIR}/libggiwmh.conf ${PKG_SYSCONFDIR}/libggiwmh.conf

.include "../../graphics/libggi/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
