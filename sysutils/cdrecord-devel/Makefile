# $NetBSD: Makefile,v 1.1.1.1 2002/09/29 08:26:54 lukem Exp $

DISTNAME=	cdrtools-1.11a34
PKGNAME=	cdrecord-devel-1.11a34
WRKSRC=		${WRKDIR}/${DISTNAME:C/a.*//}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/alpha/

MAINTAINER=	lukem@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/research/cc/glone/employees/joerg.schilling/private/cdrecord.html
COMMENT=	This program allows you to create CD's on a CD-Recorder

CONFLICTS=	mkisofs-[0-9]*

.include "../../mk/bsd.prefs.mk"

USE_BUILDLINK2=		# defined
USE_GMAKE=		# defined
TBL?=			tbl

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

post-build:
	cd ${WRKSRC};							\
	for f in cdda2wav/cdda2wav.1 mkisofs/mkisofs.8; do		\
		${TBL} $${f} > $${f}.tmp;				\
		${MV} -f $${f}.tmp $${f};				\
	done

do-install:
	cd ${WRKSRC}/cdda2wav;						\
		${INSTALL_PROGRAM} OBJ/*/cdda2wav ${PREFIX}/bin;	\
		${INSTALL_MAN} cdda2wav.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} OBJ/*/cdrecord ${PREFIX}/bin;	\
		${INSTALL_MAN} cdrecord.1 ${PREFIX}/man/man1
	cd ${WRKSRC}/mkisofs;						\
		${INSTALL_PROGRAM} OBJ/*/mkisofs ${PREFIX}/bin;		\
		${INSTALL_MAN} mkisofs.8 ${PREFIX}/man/man8
	cd ${WRKSRC}/readcd;						\
		${INSTALL_PROGRAM} OBJ/*/readcd ${PREFIX}/bin;		\
		${INSTALL_MAN} readcd.1 ${PREFIX}/man/man1

.include "../../mk/ossaudio.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
