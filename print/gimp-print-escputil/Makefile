# $NetBSD: Makefile,v 1.14 2004/02/14 17:21:50 jlam Exp $

DISTNAME=	gimp-print-4.2.5
PKGNAME=	gimp-print-escputil-4.2.5
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gimp-print/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gimp-print.sourceforge.net/
COMMENT=	Epson Stylus inkjet printer tool

#the lib is not really needed, but the build system wants it
BUILDLINK_DEPMETHOD.gimp-print-lib=	build
CONFLICTS+=	gimp<=1.2.3

GNU_CONFIGURE=	YES
CONFIGURE_ARGS+= --without-samples --without-user-guide
CONFIGURE_ARGS+= --without-gimp
CONFIGURE_ARGS+= --without-cups --without-translated-ppds
CONFIGURE_ARGS+= --enable-libgimpprint=no
USE_LIBTOOL=	yes
USE_GNU_TOOLS+=	make
USE_BUILDLINK2=	yes

.include "../../print/gimp-print-lib/buildlink2.mk"
.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../devel/readline/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
