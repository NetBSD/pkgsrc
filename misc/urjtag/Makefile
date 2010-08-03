# $NetBSD: Makefile,v 1.3 2010/08/03 15:22:27 drochner Exp $
#

DISTNAME=	urjtag-0.10
PKGREVISION=	1
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
.include "../../mk/bsd.pkg.mk"
