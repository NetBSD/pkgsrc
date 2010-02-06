# $NetBSD: Makefile,v 1.44 2010/02/06 22:19:38 gdt Exp $

DISTNAME=	hdf5-1.6.10
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	ftp://ftp.hdfgroup.org/HDF5/current16/src/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.hdfgroup.org/HDF5/
COMMENT=	Hierarchical Data Format (new generation)

LICENSE=	original-bsd

USE_LIBTOOL=		yes
USE_TOOLS+=		pax tr
GNU_CONFIGURE=		yes
TEST_TARGET=		check
PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS+=	include lib bin share/examples/hdf5/c

# it appears that this file is informative only and is not actually
# used by any installed tools
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libhdf5.settings

.include "options.mk"

INSTALL_ENV+=		INSTALL_SCRIPT=${INSTALL_SCRIPT:Q}
INSTALLATION_DIRS+=	share/doc/hdf5
INSTALLATION_DIRS+=	share/doc/hdf5/html

post-extract:
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsd
	${CP} ${WRKSRC}/config/freebsd ${WRKSRC}/config/netbsdelf

post-install:
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5cc ${DESTDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/tools/misc/h5redeploy.in ${DESTDIR}${PREFIX}/bin/h5redeploy
	cd ${WRKSRC} && ${INSTALL_DATA} COPYING release_docs/HISTORY.txt \
		release_docs/RELEASE.txt ${DESTDIR}${PREFIX}/share/doc/hdf5
	# avoid installing the Makefile and Makefile.in's  They are not needed
	cd ${WRKSRC}/doc/html && pax -s '/.*Makefile.*//' -rwpm . ${DESTDIR}${PREFIX}/share/doc/hdf5/html
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/share/doc/hdf5/html

.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
