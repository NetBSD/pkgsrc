# $NetBSD: Makefile,v 1.22 2013/01/17 15:49:44 joerg Exp $

DISTNAME=	libstatgrab-0.17
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.uk.i-scream.org/pub/i-scream/libstatgrab/ \
		ftp://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://www.mirrorservice.org/sites/ftp.i-scream.org/pub/i-scream/libstatgrab/ \
		http://dl.ambiweb.de/mirrors/ftp.i-scream.org/libstatgrab/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.i-scream.org/libstatgrab/
COMMENT=	Provides a useful interface to system statistics
LICENSE=	gnu-gpl-v2

.include "options.mk"

USE_TOOLS+=		pkg-config perl:run

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE=	libstatgrab.pc.in

REPLACE_PERL+=		src/statgrab/statgrab-make-mrtg-config.in
REPLACE_PERL+=		src/statgrab/statgrab-make-mrtg-index.in

CONFIGURE_ARGS+=	--disable-examples

CPPFLAGS.NetBSD+=	-D_KMEMUSER

.include "../../mk/bsd.pkg.mk"
