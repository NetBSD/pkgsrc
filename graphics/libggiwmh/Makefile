# $NetBSD: Makefile,v 1.5 2004/10/03 00:14:55 tv Exp $
#

DISTNAME=		libggiwmh-0.1.0.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			ftp://ftp.ggi-project.org/pub/ggi/extensions/libwmh/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggiwmh.html
COMMENT=		Windows Manager hints library for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggiwmh
CONF_FILES=		${EGDIR}/libggiwmh.conf ${PKG_SYSCONFDIR}/libggiwmh.conf

.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
