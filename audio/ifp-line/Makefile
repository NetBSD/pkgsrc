# $NetBSD: Makefile,v 1.11 2011/06/18 10:01:28 shattered Exp $

DISTNAME=		ifp-line-0.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=		sekiya@NetBSD.org
HOMEPAGE=		http://ifp-driver.sourceforge.net/
COMMENT=		Command-line interface to iRiver MP3 players

PKG_DESTDIR_SUPPORT=	user-destdir

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin

GNU_CONFIGURE=		yes

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
