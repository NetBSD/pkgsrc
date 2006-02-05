# $NetBSD: Makefile,v 1.6 2006/02/05 23:09:34 joerg Exp $

DISTNAME=		libggimisc-2.1.1.src
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
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

PKG_SYSCONFSUBDIR=	ggi
EGDIR=			${PREFIX}/share/examples/libggimisc
CONF_FILES=		${EGDIR}/libggimisc.conf ${PKG_SYSCONFDIR}/libggimisc.conf

.include "../../graphics/libggi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
