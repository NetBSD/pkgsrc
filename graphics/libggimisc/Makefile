# $NetBSD: Makefile,v 1.3 2005/04/11 21:46:06 tv Exp $

DISTNAME=		libggimisc-2.1.0.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		1
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/} \
			http://www.ggi-project.org/ftp/ggi/v2.1/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.ggi-project.org/packages/libggimisc.html
COMMENT=		Miscellaneous graphics target features for GGI

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_PKGINSTALL=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggimisc
CONF_FILES=		${EGDIR}/libggimisc.conf ${PKG_SYSCONFDIR}/libggimisc.conf

.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
