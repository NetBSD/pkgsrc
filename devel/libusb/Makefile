# $NetBSD: Makefile,v 1.44 2019/08/06 09:12:10 maya Exp $

DISTNAME=	libusb-0.1.12
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=libusb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://libusb.sourceforge.net/
COMMENT=	USB access library (version 0)
LICENSE=	gnu-lgpl-v2.1

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-build-docs
PKGCONFIG_OVERRIDE+=	libusb.pc.in

# The configure script recognizes only specific OSes that have one of
# three USB APIs: Linux, BSD, or MacOS. If you have some other OS that
# supports one of these APIs, add it here and also in the configure
# script. Solaris support has been hacked on separately.
ONLY_FOR_PLATFORM=	Linux-*-*
ONLY_FOR_PLATFORM+=	NetBSD-*-* OpenBSD-*-* FreeBSD-*-*
ONLY_FOR_PLATFORM+=	Darwin-*-*
ONLY_FOR_PLATFORM+=	SunOS-*-*

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
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} usb.h.in >usb.h
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} libusb-config.in >libusb-config
	cd ${WRKSRC} && ${SED} ${SED_TRANSFORMS} libusb.pc.in >libusb.pc
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

BUILDLINK_TRANSFORM+=	rm:-Werror

.include "../../mk/bsd.pkg.mk"
