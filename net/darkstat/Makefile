# $NetBSD: Makefile,v 1.3 2006/10/07 07:49:01 obache Exp $
#

DISTNAME=		darkstat-3.0.540
CATEGORIES=		net
MASTER_SITES=		http://dmr.ath.cx/net/darkstat/
DIST_SUBDIR=		darkstat
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		bartosz@atom.eu.org
HOMEPAGE=		http://dmr.ath.cx/net/darkstat/
COMMENT=		Network statistics gatherer

SUBST_CLASSES+=		conv_c
SUBST_STAGE.conv_c=	post-patch
SUBST_FILES.conv_c=	conv.c
SUBST_SED.conv_c=	-e 's,/var/empty,${PREFIX}/share/darkstat/chroot,'

BUILD_TARGET=		darkstat

GNU_CONFIGURE=		yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat
	${INSTALL_DATA_DIR} ${PREFIX}/share/darkstat/chroot

.include "../../devel/zlib/buildlink3.mk"
.include "../../net/libpcap/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
