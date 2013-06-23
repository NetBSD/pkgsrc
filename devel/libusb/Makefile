# $NetBSD: Makefile,v 1.35 2013/06/23 16:59:16 jperkin Exp $

DISTNAME=	libusb-0.1.12
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library (version 0)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
GCC_REQD+=		3.3
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-docs
PKGCONFIG_OVERRIDE+=	libusb.pc.in

ONLY_FOR_PLATFORM=	Darwin-*-* FreeBSD-*-* Linux-*-* NetBSD-*-*
ONLY_FOR_PLATFORM+=	OpenBSD-*-* DragonFly-*-* SunOS-*-*

TEST_TARGET=		check

CONFLICTS=		libusb-compat-[0-9]*

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=		-D_REENTRANT -D_TS_ERRNO
CXXFLAGS+=		-Du_int8_t=uint8_t
CXXFLAGS+=		-Du_int16_t=uint16_t
CXXFLAGS+=		-Du_int32_t=uint32_t
SED_TRANSFORMS=		-e 's,@BIGENDIAN@,0,' -e 's,@LINUX_API@,0,'
SED_TRANSFORMS+=	-e 's,u_int8_t,uint8_t,g'
SED_TRANSFORMS+=	-e 's,u_int16_t,uint16_t,g'
SED_TRANSFORMS+=	-e 's,u_int32_t,uint32_t,g' 
SED_TRANSFORMS+=	-e "s,@prefix@,${PREFIX},g"
SED_TRANSFORMS+=	-e "s,@exec_prefix@,${PREFIX},g"
SED_TRANSFORMS+=	-e "s,@LIBUSB_VERSION@,${PKGVERSION_NOREV},g"
SED_TRANSFORMS+=	-e "s,@VERSION@,${PKGVERSION_NOREV},g"
SED_TRANSFORMS+=	-e "s,@includedir@,${PREFIX}/include,g"
SED_TRANSFORMS+=	-e "s,@libdir@,${PREFIX}/lib,g"
SED_TRANSFORMS+=	-e "s,@OSLIBS@,,g"

INSTALLATION_DIRS+=	bin include lib/pkgconfig

do-configure:
	cp ${FILESDIR}/libusbugen* ${WRKSRC}/

do-build:
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile --tag=CC ${CC} ${CFLAGS} \
	    -I. -c libusbugen.c
	cd ${WRKSRC} && ${LIBTOOL} --mode=link --tag=CC ${CC} \
	    -rpath ${PREFIX}/lib -version-info 8:4:4 -release 0.1 \
	    -o libusb.la libusbugen.lo
	cd ${WRKSRC} && ${LIBTOOL} --mode=compile --tag=CXX ${CXX} ${CXXFLAGS} \
	    -I. -c usbpp.cpp
	cd ${WRKSRC} && ${LIBTOOL} --mode=link --tag=CXX ${CXX} \
	    -rpath ${PREFIX}/lib -version-info 8:4:4 -release 0.1 \
	    -o libusbpp.la usbpp.lo
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} usb.h.in >usb.h
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} libusb-config.in >libusb-config
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} libusb.pc.in >libusb.pc

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/libusb-config ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/usb.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/usbpp.h ${DESTDIR}${PREFIX}/include
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libusb.la \
	    ${DESTDIR}${PREFIX}/lib
	cd ${WRKSRC} && ${LIBTOOL} --mode=install ${INSTALL_LIB} libusbpp.la \
	    ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/libusb.pc ${DESTDIR}${PREFIX}/lib/pkgconfig
.endif

.include "../../mk/bsd.pkg.mk"
