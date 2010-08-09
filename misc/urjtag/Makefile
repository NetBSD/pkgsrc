# $NetBSD: Makefile,v 1.4 2010/08/09 19:37:45 drochner Exp $
#

DISTNAME=	urjtag-0.10
PKGREVISION=	2
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
