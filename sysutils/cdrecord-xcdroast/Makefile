# $NetBSD: Makefile,v 1.1.1.1 2002/12/02 18:41:20 drochner Exp $

DISTNAME=	cdrtools-1.11a40
PKGNAME=	cdrecord-xcdroast098a11-1.10.40
WRKSRC=		${WRKDIR}/${DISTNAME:C/a.*//}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/alpha/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	cdrecord bits for xcdroast

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM=	r:-I/opt/schily
BUILDLINK_TRANSFORM+=	r:-L/opt/schily
.endif

# avoid picking up a bad ${ARCH} during the build
MAKE_ENV+=      ARCH=""
MAKE_ENV+=      MAKEPROG="gmake"

do-configure:
	cd ${WRKSRC}/RULES;						\
	for suffix in netbsd-cc.rul netbsd-gcc.rul; do			\
		if [ ! -f ${MACHINE}-$$suffix ]; then			\
			${LN} -sf i386-$$suffix ${MACHINE}-$$suffix;	\
		fi;							\
	done

XCDRTOOLDIR=	${PREFIX}/lib/xcdroast-0.98/bin

do-install:
	${INSTALL_DATA_DIR} ${XCDRTOOLDIR}
	cd ${WRKSRC}/cdda2wav;						\
		${INSTALL_PROGRAM} OBJ/*/cdda2wav ${XCDRTOOLDIR}
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} OBJ/*/cdrecord ${XCDRTOOLDIR}
	cd ${WRKSRC}/mkisofs;						\
		${INSTALL_PROGRAM} OBJ/*/mkisofs ${XCDRTOOLDIR}
	cd ${WRKSRC}/readcd;						\
		${INSTALL_PROGRAM} OBJ/*/readcd ${XCDRTOOLDIR}

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
