# $NetBSD: Makefile,v 1.8 2008/03/03 17:45:36 jlam Exp $

DISTNAME=	${PKGNAME_NOREV}-5.src.rpm
PKGNAME=	newt-0.51.6
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	http://download.fedora.redhat.com/pub/fedora/linux/core/3/SRPMS/
EXTRACT_SUFX=	# empty

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Windowing toolkit based on libslang

BUILD_DEPENDS+=	rpm2pkg>=2.0:../../pkgtools/rpm2pkg

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake gzcat tar

USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

INSTALLATION_DIRS=	bin include lib

do-extract:
	${LOCALBASE}/sbin/rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}
	cd ${WRKDIR} ; ${GZCAT} ${WRKSRC}.tar.gz | ${TAR} -xf -

do-install:
	cd ${WRKSRC}; \
	 ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libnewt.la ${DESTDIR}${PREFIX}/lib;\
	 ${INSTALL_DATA} newt.h ${DESTDIR}${PREFIX}/include; \
	 ${LIBTOOL} --mode=install ${INSTALL} whiptail ${DESTDIR}${PREFIX}/bin

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
