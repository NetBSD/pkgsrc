# $NetBSD: Makefile,v 1.40.2.1 2014/10/29 20:11:31 tron Exp $

DISTNAME=	libgpg-error-1.15
PKGREVISION=	1
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

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes
MAKE_ENV+=		LC_ALL="C"
MAKE_JOBS_SAFE=		no

.include "../../mk/bsd.prefs.mk"

.if !empty(USE_CROSS_COMPILE:M[yY][eE][sS])
CONFIGURE_ENV+=		CC_FOR_BUILD=${NATIVE_CC:Q}
.else
CONFIGURE_ENV+=		CC_FOR_BUILD=${CC:Q}\ ${CFLAGS:M*:Q}
.endif

# XXX See HACKS
.if ${OPSYS} == "IRIX" || !empty(MACHINE_PLATFORM:MNetBSD-[3-9]*)
USE_TOOLS+=		awk
.else
USE_TOOLS+=		gawk
.endif

# On Dragonfly i386, Pkgsrc libintl segfaults on bindtextdomain function
# while locking a thread.  Until that's resolved, stop libgpg-error from
# using NLS which invokes that function during initialization.
PLIST_VARS+=	nls
.if ${OPSYS} == "DragonFly" && ${MACHINE} == "i386"
CONFIGURE_ARGS+=	--disable-nls
.else
PLIST.nls=	yes
.endif

TEST_TARGET=		check

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
