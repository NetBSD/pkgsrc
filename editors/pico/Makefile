# $NetBSD: Makefile,v 1.61 2005/02/15 18:04:02 tv Exp $
#
# NOTE:
# When updating, it is necessary to change the shlib version, located in
# patch-aa.  If you do not KNOW that the new version is backwards ABI
# compatible (usually not, in the case of libpico), bump the major version,
# and then bump the BUILDLINK_DEPENDS in buildlink3.mk.
#

DISTNAME=	pine4.62
PKGNAME=	pico-4.9
PKGREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Text editor (ships with Pine), and Pine's text editing lib

LICENSE=	pine-license

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
BUILDNAME=	osx
LIBS+=		-lcurses
.elif ${OPSYS} == "IRIX"
.  if ${OS_VERSION} >= 6.5
BUILDNAME=	sg6
.  else
BUILDNAME=	sgi
.  endif
.elif ${OPSYS} == "Interix"
BUILDNAME=	sfu
.elif ${OPSYS} == "Linux"
BUILDNAME=	lnx
.elif ${OPSYS} == "SunOS"
BUILDNAME=	so5
.else
BUILDNAME=	neb
.endif

MAKE_ENV+=	_STRIPFLAG_INSTALL=	# debug...

pre-patch:
.if ${OPSYS} == "Interix"
	${CP} -f \
		${WRKSRC}/pico/osdep/os-sol.h ${WRKSRC}/pico/osdep/os-sfu.h
	${SED} -e 's,read.pol,read.sel,' \
		${WRKSRC}/pico/osdep/os-sv4.ic >${WRKSRC}/pico/osdep/os-sfu.ic
	${SED} -e 's,-ltermlib,-lcurses,g;s,sv4,sfu,g' \
		${WRKSRC}/pico/makefile.sv4 >${WRKSRC}/pico/makefile.sfu
.endif

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build ${BUILDNAME} \
		CC="${LIBTOOL} ${CC}" \
		PREFIX=${PREFIX} OPTIMIZE="${CFLAGS}" \
		EXTRALDFLAGS="${LIBS}"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/pico/libpico.la ${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/include/pico
	cd ${WRKSRC}/pico && ${INSTALL_DATA} *.h ${PREFIX}/include/pico

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
