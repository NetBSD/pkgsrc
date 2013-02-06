# $NetBSD: Makefile,v 1.33 2013/02/06 19:30:58 jperkin Exp $
#

DISTNAME=	libnids-1.23
PKGREVISION=	6
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.libpcap=	build

INSTALL_MAKE_FLAGS+=	install_prefix=${DESTDIR}

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
