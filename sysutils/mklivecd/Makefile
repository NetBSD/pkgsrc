# $NetBSD: Makefile,v 1.35 2007/03/09 23:51:50 xtraeme Exp $

DISTNAME=	mklivecd-0.14.5
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
COMMENT=	Make your own NetBSD/i386 Live CD-ROM/DVD-ROM

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	{cdrtools,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrtools
.if ${MACHINE_ARCH} == "i386"
DEPENDS+=	grub>=0.97:../../sysutils/grub
.endif

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386 NetBSD-*-x86_64

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	tar

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/mklivecd

FILES=	    KERN-LIVECD personal_config

do-install:
.for f in livecd mklivecd.sh mklivecd.8
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@TAR@,${TAR},g" \
		-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/mklivecd
	${INSTALL_SCRIPT} ${WRKDIR}/mklivecd.sh ${PREFIX}/sbin/mklivecd
	${INSTALL_MAN} ${WRKDIR}/mklivecd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKDIR}/livecd ${PREFIX}/share/mklivecd
.for F in ${FILES}
	${INSTALL_DATA} ${FILESDIR}/${F} ${PREFIX}/share/mklivecd
.endfor

.include "../../mk/bsd.pkg.mk"
