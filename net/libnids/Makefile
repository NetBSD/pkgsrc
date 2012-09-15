# $NetBSD: Makefile,v 1.31 2012/09/15 10:06:04 obache Exp $
#

DISTNAME=	libnids-1.23
PKGREVISION=	5
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.libpcap=	build

INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
