# $NetBSD: Makefile,v 1.15 2016/04/20 12:10:27 nros Exp $

DISTNAME=		ifp-line-0.3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=ifp-driver/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://ifp-driver.sourceforge.net/
COMMENT=		Command-line interface to iRiver MP3 players
LICENSE=		gnu-gpl-v2

INSTALL_MAKE_FLAGS+=	PREFIX=${DESTDIR}${PREFIX}
INSTALLATION_DIRS+=	bin

GNU_CONFIGURE=		yes

USE_FEATURES+=		fts_open

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/libusb/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
