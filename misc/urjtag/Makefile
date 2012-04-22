# $NetBSD: Makefile,v 1.7 2012/04/22 01:17:58 mef Exp $
#

DISTNAME=	urjtag-0.10
PKGREVISION=	3
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=urjtag/urjtag/0.10/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.urjtag.org/
COMMENT=	JTAG tool
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake msgfmt
REPLACE_SH=		src/bsdl2jtag

post-extract:
	${CP} ${FILESDIR}/usbprog.c ${WRKSRC}/src/tap/cable

.include "../../devel/readline/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../devel/libftdi/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
