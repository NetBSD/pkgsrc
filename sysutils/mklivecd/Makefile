# $NetBSD: Makefile,v 1.4 2004/04/26 17:28:58 xtraeme Exp $

DISTNAME=	mklivecd-0.4
CATEGORIES=	sysutils
MASTER_SITES=	# empty
DISTFILES=	# empty

MAINTAINER=	xtraeme@NetBSD.org
COMMENT=	Build a NetBSD i386 Live CD via command line

#DEPENDS+=	cdrecord-[0-9]*:../../sysutils/cdrecord

PKG_INSTALLATION_TYPES=	overwrite pkgviews

ONLY_FOR_PLATFORM=	NetBSD-*-i386

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	# empty
NO_CHECKSUM=	YES
NO_CONFIGURE=	YES
NO_BUILDLINK=	YES
NO_BUILD=	YES

INSTALLATION_DIRS=	share/mklivecd sbin

FILES=	    KERN-LIVECD mfs_rcd personal_config

do-install:
	@${SED} -e "s,@PREFIX@,${PREFIX},g" \
		-e "s,@MACHINE_ARCH@,${MACHINE_ARCH},g" \
		${FILESDIR}/mklivecd.sh > ${WRKDIR}/mklivecd
	${INSTALL_DATA_DIR} ${PREFIX}/share/mklivecd
	${INSTALL_SCRIPT} ${WRKDIR}/mklivecd ${PREFIX}/sbin
	${INSTALL_MAN} ${FILESDIR}/mklivecd.8 ${PREFIX}/man/man8
.for F in ${FILES}
	${INSTALL_DATA} ${FILESDIR}/${F} ${PREFIX}/share/mklivecd
.endfor

.include "../../mk/bsd.pkg.mk"
