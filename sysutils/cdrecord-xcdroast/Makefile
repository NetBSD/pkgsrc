# $NetBSD: Makefile,v 1.15 2005/12/05 20:50:59 rillig Exp $

DISTNAME=	cdrtools-2.01a21
PKGNAME=	cdrecord-xcdroast-0.98a15.2.01a21
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	cdrecord bits for xcdroast

CONFLICTS+=	cdrecord-xcdroast098a11-*
CONFLICTS+=	cdrecord-xcdroast098a13-*

.include "../../mk/bsd.prefs.mk"

WRKSRC=			${WRKDIR}/${DISTNAME:C/a.*//}
USE_TOOLS+=		gmake

.if ${LOCALBASE} != "/opt/schily"
BUILDLINK_TRANSFORM+=	rmdir:/opt/schily
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

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
