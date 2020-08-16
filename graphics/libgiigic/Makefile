# $NetBSD: Makefile,v 1.10 2020/08/16 22:38:56 tnn Exp $
#

DISTNAME=		libgiigic-1.0.0.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics devel
#MASTER_SITES=		http://www.ggi-project.org/ftp/ggi/v2.1/
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.ggi-project.org/packages/libgiigic.html
HOMEPAGE=		https://ibiblio.org/ggicore/
COMMENT=		General Input Configurator for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libgiigic
CONF_FILES=		${EGDIR}/libgiigic.conf ${PKG_SYSCONFDIR}/libgiigic.conf

.include "../../mk/bsd.prefs.mk"

CPPFLAGS+=		-DGG_NEED_OLD_INTTYPES

.include "../../graphics/libgii/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
