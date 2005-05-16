# $NetBSD: Makefile,v 1.19 2005/05/16 01:32:23 jlam Exp $

DISTNAME=	mklivecd-0.11
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
COMMENT=	Build a NetBSD i386 Live CD via command line

DEPENDS+=	{cdrecord,cdrtools-ossdvd}-[0-9]*:../../sysutils/cdrecord
DEPENDS+=	grub>=0.96:../../sysutils/grub

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILD=	YES
USE_TOOLS+=	tar

INSTALLATION_DIRS=	man/man8 sbin share/mklivecd

FILES=	    KERN-LIVECD personal_config

do-install:
.for f in mfs_rcd mklivecd.sh
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@LOCALBASE@,${LOCALBASE},g" \
		-e "s,@TAR@,${TAR},g" \
		-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		${FILESDIR}/${f} > ${WRKDIR}/${f}
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/mklivecd
	${INSTALL_SCRIPT} ${WRKDIR}/mklivecd.sh ${PREFIX}/sbin/mklivecd
	${INSTALL_MAN} ${FILESDIR}/mklivecd.8 ${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKDIR}/mfs_rcd ${PREFIX}/share/mklivecd
.for F in ${FILES}
	${INSTALL_DATA} ${FILESDIR}/${F} ${PREFIX}/share/mklivecd
.endfor

.include "../../mk/bsd.pkg.mk"
