# $NetBSD: Makefile,v 1.2 2008/12/22 02:46:52 jmcneill Exp $
#
.include "Makefile.version"

DISTNAME=	libatomic_ops-${LIBATOMIC_OPS_SNAPDATE}
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bdwgc.sourceforge.net/
COMMENT=	Multi-platform library of atomic operations by Hans Boehm

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/libatomic_ops-${LIBATOMIC_OPS_VERSION}
GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake automake autoconf autoreconf
USE_LIBTOOL=	yes
TEST_TARGET=	check

INSTALL_MAKE_FLAGS=	pkgdatadir=${PKGDOCDIR:Q}
PKGDOCDIR=		${PREFIX}/share/doc/libatomic_ops

pre-configure:
	cd ${WRKSRC} && autoreconf -vif

post-install:
	${INSTALL_DATA} ${WRKSRC}/src/atomic_ops/sysdeps/README \
		${DESTDIR}${PKGDOCDIR}/README_headers.txt

.include "../../mk/bsd.pkg.mk"
