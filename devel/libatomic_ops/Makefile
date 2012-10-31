# $NetBSD: Makefile,v 1.6 2012/10/31 11:17:10 asau Exp $
#
.include "Makefile.version"

DISTNAME=	libatomic_ops-${LIBATOMIC_OPS_SNAPDATE}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_LOCAL}
#MASTER_SITES=	http://ryo-on.users.sourceforge.net/distrib/
LICENSE=	gnu-gpl-v2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bdwgc.sourceforge.net/
COMMENT=	Multi-platform library of atomic operations by Hans Boehm

WRKSRC=		${WRKDIR}/libatomic_ops
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
