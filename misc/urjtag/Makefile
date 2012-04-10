# $NetBSD: Makefile,v 1.5 2012/04/10 15:24:59 mef Exp $
#

DISTNAME=	urjtag-0.10
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	http://downloads.sourceforge.net/project/urjtag/urjtag/0.10/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://downloads.sourceforge.net/project/urjtag/urjtag/0.10/
COMMENT=	JTAG tool
#LICENSE=	# TODO: (see mk/license.mk)

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
REPLACE_SH=		src/bsdl2jtag

post-extract:
	${CP} ${FILESDIR}/usbprog.c ${WRKSRC}/src/tap/cable

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/libftdi/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
