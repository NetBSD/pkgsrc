# $NetBSD: Makefile,v 1.18 2004/11/25 14:13:32 adam Exp $

DISTNAME=	gimp-print-4.2.7
PKGNAME=	gimp-print-cups-4.2.7
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print plugin

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-escputil=no --enable-libgimpprint=no
CONFIGURE_ARGS+=	--with-cups=${PREFIX}
CONFIGURE_ARGS+=	--without-samples --without-user-guide
CONFIGURE_ARGS+=	--without-gimp --without-translated-ppds
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}
PKG_SYSCONFSUBDIR=	cups

EGDIR=		${PREFIX}/share/examples/cups
CONF_FILES=	${EGDIR}/config.types ${PKG_SYSCONFDIR}/config.types

.include "../../print/cups/buildlink3.mk"
.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
