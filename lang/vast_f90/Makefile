# $NetBSD: Makefile,v 1.1.1.1 1999/09/16 13:35:34 wennmach Exp $
#

DISTNAME=		vf90_per
PKGNAME=		vast_f90-3.4N5
CATEGORIES=		lang emulators
MASTER_SITES=		ftp://ftp.psrv.com/vast/vastf90/linux-x86/
EXTRACT_SUFX=		.tar

MAINTAINER=		wennmach@netbsd.org
HOMEPAGE=		http://www.psrv.com/lnxf90.html

ONLY_FOR_PLATFORM= 	NetBSD-*-i386

NO_BUILD=		yes

EMULSUBDIR=             emul/linux
EMULDIR=                ${PREFIX}/${EMULSUBDIR}
BINDIR=                 ${PREFIX}/bin
MANDIR=			${PREFIX}/man/cat1
DOCDIR=			${PREFIX}/share/doc/vast_f90

LICENSE=		fee-based-commercial-use

EXTRACT_CMD=		${MKDIR} ${DISTNAME}; tar xf ${_DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -C ${DISTNAME}
UNCOMPRESS=		/usr/bin/uncompress

.include "../../mk/bsd.prefs.mk"

.if !exists(/emul/linux/usr/bin/g77)
IGNORE= requires Linux toolchain as provided e. g. by emulators/suse_devel
.endif

do-install:
	${UNCOMPRESS} ${WRKDIR}/${DISTNAME}/f90.Z
	${UNCOMPRESS} ${WRKDIR}/${DISTNAME}/vf90.Z
	${UNCOMPRESS} ${WRKDIR}/${DISTNAME}/libvast90.a.Z
	${UNCOMPRESS} ${WRKDIR}/${DISTNAME}/90to77.ps.Z
	${INSTALL} -m 755 -g wheel -o root ${WRKDIR}/${DISTNAME}/f90 ${EMULDIR}/usr/bin
	${INSTALL} -m 755 -g wheel -o root ${WRKDIR}/${DISTNAME}/vf90 ${EMULDIR}/usr/bin
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/libvast90.a ${EMULDIR}/usr/lib
	-${MKDIR} ${EMULDIR}/usr/man/cat1
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/f90.0 ${EMULDIR}/usr/man/cat1
	${MKDIR} ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/90to77.ps ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/LICENSE ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/README ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/restrict.txt ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/vastf90.pdf ${EMULDIR}/usr/share/doc/vast_f90
	${INSTALL} -m 644 -g wheel -o root ${WRKDIR}/${DISTNAME}/versions.txt ${EMULDIR}/usr/share/doc/vast_f90

	-${MKDIR} ${BINDIR}
	${LN} -fs ${EMULDIR}/usr/bin/f90 ${BINDIR}/f90
	${LN} -fs ${EMULDIR}/usr/bin/vf90 ${BINDIR}/vf90
	-${MKDIR} ${MANDIR}
	${LN} -fs ${EMULDIR}/usr/man/cat1/f90.0 ${MANDIR}/f90.0
	${LN} -fs ${EMULDIR}/usr/man/cat1/f90.0 ${MANDIR}/vf90.0
	${MKDIR} ${DOCDIR}
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/90to77.ps ${DOCDIR}/90to77.ps
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/LICENSE ${DOCDIR}/LICENSE
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/README ${DOCDIR}/README
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/restrict.txt ${DOCDIR}/restrict.txt
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/vastf90.pdf ${DOCDIR}/vastf90.pdf
	${LN} -fs ${EMULDIR}/usr/share/doc/vast_f90/versions.txt ${DOCDIR}/versions.txt

.include "../../mk/bsd.pkg.mk"
