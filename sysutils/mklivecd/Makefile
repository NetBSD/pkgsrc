# $NetBSD: Makefile,v 1.43 2008/01/24 20:09:14 xtraeme Exp $

DISTNAME=	mklivecd-0.15.3
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

# Please don't commit to that package without permission from
# Juan Romero Pardines <xtraeme at NetBSD dot org>.
MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://mklivecd.xtrarom.org/
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
USE_TOOLS+=	tar

INSTALLATION_DIRS=	${PKGMANDIR}/man8 sbin share/mklivecd

do-build:
.for f in livecd mklivecd.sh mklivecd.8
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@TAR@,${TAR},g" \
		-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/mklivecd.sh ${PREFIX}/sbin/mklivecd
	${INSTALL_MAN} ${WRKDIR}/mklivecd.8 ${PREFIX}/${PKGMANDIR}/man8
	${INSTALL_DATA} ${WRKDIR}/livecd ${PREFIX}/share/mklivecd
	${INSTALL_DATA} ${FILESDIR}/personal_config ${PREFIX}/share/mklivecd

.include "../../mk/bsd.pkg.mk"
