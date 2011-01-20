# $NetBSD: Makefile,v 1.32 2011/01/20 07:43:02 adam Exp $

DISTNAME=	libgpg-error-1.10
CATEGORIES=	security
MASTER_SITES=	ftp://ftp.gnupg.org/gcrypt/libgpg-error/ \
		ftp://ftp.ring.gr.jp/pub/net/gnupg/libgpg-error/ \
		ftp://mirror.switch.ch/mirror/gnupg/libgpg-error/ \
		ftp://ftp.freenet.de/pub/ftp.gnupg.org/gcrypt/libgpg-error/ \
		ftp://ftp.gnupg.ca/libgpg-error/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.gnupg.org/
COMMENT=	Definitions of common error values for all GnuPG components
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
MAKE_ENV+=		LC_ALL="C"
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

# XXX See HACKS
.if ${OPSYS} == "IRIX" || !empty(MACHINE_PLATFORM:MNetBSD-[3-9]*)
USE_TOOLS+=		nawk
.else
USE_TOOLS+=		gawk
.endif

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
