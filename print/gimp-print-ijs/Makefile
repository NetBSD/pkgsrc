# $NetBSD: Makefile,v 1.10 2004/01/24 14:58:00 grant Exp $

DISTNAME=	gimp-print-4.2.5
PKGNAME=	gimp-print-ijs-4.2.5
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITES_SOURCEFORGE:=gimp-print/}

MAINTAINER=	jlam@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	GIMP print IJS server

USE_BUILDLINK2=		# defined
USE_GNU_TOOLS+=		make

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-ijs
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--without-user-guide
CONFIGURE_ARGS+=	--without-gimp
CONFIGURE_ARGS+=	--without-cups
CONFIGURE_ARGS+=	--without-translated-ppds
CONFIGURE_ARGS+=	--disable-escputil
CONFIGURE_ARGS+=	--disable-libgimpprint

USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

BUILD_DIRS=		${WRKSRC}/lib ${WRKSRC}/src/ghost
DOCDIR=			${PREFIX}/share/doc/gimp-print-ijs

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/src/ghost/README ${DOCDIR}

.include "../../print/gimp-print-lib/buildlink2.mk"
.include "../../print/ijs/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
