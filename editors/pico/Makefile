# $NetBSD: Makefile,v 1.78 2012/10/03 11:43:42 asau Exp $
#
# NOTE:
# When updating, it is necessary to change the shlib version, located in
# several files in patches/.  If you do not KNOW that the new version is
# backwards ABI compatible (usually not), bump the major version,
# and then bump the BUILDLINK_API_DEPENDS in buildlink3.mk.

DISTNAME=	pine4.64
PKGNAME=	pico-4.10
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.cac.washington.edu/pine/ \
		ftp://ftp.fu-berlin.de/unix/mail/pine/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.washington.edu/pine/
COMMENT=	Text editor (ships with Pine), and Pine's text editing lib
LICENSE=	pine-license

USE_LIBTOOL=		yes

.include "../../mk/bsd.prefs.mk"

OPSYSVARS+=		BUILDNAME
BUILDNAME.Darwin=	osx
.if ${OPSYS} == "IRIX"
.  if ${OS_VERSION} >= 6.5
BUILDNAME.IRIX=		sg6
.  else
BUILDNAME.IRIX=		sgi
.  endif
.endif
BUILDNAME.Interix=	sfu
BUILDNAME.Linux=	lnx
BUILDNAME.SunOS=	so5
BUILDNAME.NetBSD=	neb
BUILDNAME.*=		neb

# Let termcap.buildlink3.mk handle using the right termcap library.
LIBS+=			${BUILDLINK_LDADD.termcap}

MAKE_ENV+=	_STRIPFLAG_INSTALL=	# debug...

INSTALLATION_DIRS=	bin include/pico lib ${PKGMANDIR}/man1

# Create the OS-dependent files for Interix from the Solaris ones.
post-extract:
	${CP} -f ${WRKSRC}/pico/osdep/os-sol.h ${WRKSRC}/pico/osdep/os-sfu.h
	${SED} -e 's,read.pol,read.sel,' \
		${WRKSRC}/pico/osdep/os-sv4.ic >${WRKSRC}/pico/osdep/os-sfu.ic
	${SED} -e 's,sv4,sfu,g' \
		${WRKSRC}/pico/makefile.sv4 >${WRKSRC}/pico/makefile.sfu

do-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./build ${BUILDNAME} \
		CC="${LIBTOOL} --mode=compile ${CC}" \
		LDCC="${LIBTOOL} --mode=link ${CC}" \
		PREFIX=${PREFIX} OPTIMIZE="${CFLAGS}" \
		EXTRALDFLAGS="${LIBS}"

do-install:
	${LIBTOOL} --mode=install ${INSTALL_LIB} \
		${WRKSRC}/pico/libpico.la ${DESTDIR}${PREFIX}/lib
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} \
		${WRKSRC}/pico/pico ${WRKSRC}/pico/pilot ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/pico.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/doc/pilot.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	cd ${WRKSRC}/pico && ${INSTALL_DATA} *.h ${DESTDIR}${PREFIX}/include/pico

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
