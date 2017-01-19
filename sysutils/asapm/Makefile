# $NetBSD: Makefile,v 1.43 2017/01/19 18:52:25 agc Exp $
#

DISTNAME=		asapm-2.11
PKGREVISION=	4
CATEGORIES=		sysutils x11
MASTER_SITES=		http://www.tigr.net/afterstep/download/asapm/
MASTER_SITES+=		ftp://ftp.afterstep.org/apps/asapm/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.tigr.net/afterstep/view.php?applet=asapm/data
COMMENT=		Laptop battery status display for X11
LICENSE=		gnu-gpl-v2

.if !exists(/usr/include/machine/apmvar.h)
PKG_FAIL_REASON+=	"APM needs /usr/include/machine/apmvar.h to build."
.endif

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-jpeg	# there actually is no JPEG support
CONFIGURE_ARGS+=	--with-xpm
CONFIGURE_ARGS+=	--with-xpm-includes=${BUILDLINK_PREFIX.libXpm}/include
CONFIGURE_ARGS+=	--with-xpm-library=${BUILDLINK_PREFIX.libXpm}/lib

INSTALLATION_DIRS+=	bin ${PKGMANDIR}/man1

.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
