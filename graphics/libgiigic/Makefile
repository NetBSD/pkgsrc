# $NetBSD: Makefile,v 1.4 2006/02/05 23:09:35 joerg Exp $
#

DISTNAME=		libgiigic-1.0.0.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			http://www.ggi-project.org/ftp/ggi/v2.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libgiigic.html
COMMENT=		General Input Configurator for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libgiigic
CONF_FILES=		${EGDIR}/libgiigic.conf ${PKG_SYSCONFDIR}/libgiigic.conf

.include "../../graphics/libgii/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
