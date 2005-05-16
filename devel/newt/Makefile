# $NetBSD: Makefile,v 1.3 2005/05/16 01:32:22 jlam Exp $

DISTNAME=	${PKGNAME_NOREV}-5.src.rpm
PKGNAME=	newt-0.51.6
PKGREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://download.fedora.redhat.com/pub/fedora/linux/core/3/SRPMS/
EXTRACT_SUFX=	# empty

MAINTAINER=	riz@NetBSD.org
HOMEPAGE=	# empty
COMMENT=	Windowing toolkit based on libslang

BUILD_DEPENDS+=	rpm2pkg>=2.0:../../pkgtools/rpm2pkg

USE_GNU_TOOLS+=		make gzcat
PKGSRC_USE_TOOLS+=	tar

USE_LIBTOOL=	yes
NO_EXPORT_CPP=	yes
GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

do-extract:
	${LOCALBASE}/sbin/rpm2pkg -d ${WRKDIR} ${DISTDIR}/${DISTNAME}
	cd ${WRKDIR} ; ${GZCAT} ${WRKSRC}.tar.gz | ${TAR} -xf -

do-install:
	cd ${WRKSRC}; \
	 ${LIBTOOL} --mode=install ${INSTALL_PROGRAM} libnewt.la ${PREFIX}/lib;\
	 ${INSTALL_DATA} newt.h ${PREFIX}/include; \
	 ${LIBTOOL} --mode=install ${INSTALL} whiptail ${PREFIX}/bin

.include "../../devel/libslang/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
