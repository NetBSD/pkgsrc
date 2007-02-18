# $NetBSD: Makefile,v 1.21 2007/02/18 18:53:10 adrianp Exp $
#

DISTNAME=	libnids-1.20
PKGREVISION=	1
CATEGORIES=	net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libnids/}

MAINTAINER=	cube@NetBSD.org
HOMEPAGE=	http://libnids.sourceforge.net/
COMMENT=	Network monitoring library with TCP/IP reassembly

GNU_CONFIGURE=	yes

BUILDLINK_DEPMETHOD.libpcap=	build

SUBST_CLASSES+=		conf
SUBST_STAGE.conf=	pre-configure
SUBST_FILES.conf=	configure
SUBST_MESSAGE.conf=	Fixing configuration script.

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
