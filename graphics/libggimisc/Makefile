# $NetBSD: Makefile,v 1.13 2024/05/06 08:40:27 jperkin Exp $

DISTNAME=		libggimisc-2.2.2.src
PKGNAME=		${DISTNAME:S/.src//}
PKGREVISION=		2
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ggi/}
MASTER_SITES+=		http://www.ggi-project.org/ftp/ggi/v2.2/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
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
