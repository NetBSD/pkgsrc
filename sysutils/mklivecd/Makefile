# $NetBSD: Makefile,v 1.38 2007/04/11 11:51:35 xtraeme Exp $

DISTNAME=	mklivecd-0.15.1
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
COMMENT=	Make your own NetBSD/x86 Live CD-ROM/DVD-ROM

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
	${INSTALL_DATA} ${FILESDIR}/personal_config ${PREFIX}/share/mklivecd

.include "../../mk/bsd.pkg.mk"
