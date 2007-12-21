# $NetBSD: Makefile,v 1.7 2007/12/21 13:26:42 agc Exp $

DISTNAME=	netbsd-iscsi-20071221
PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-initiator/}
CATEGORIES=	devel
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	NetBSD's iSCSI initiator (per iSCSI RFC 3720)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
BUILD_TARGET=	all-initiator

INSTALLATION_DIRS_FROM_PLIST=	yes

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/iscsifs ${DESTDIR}${PREFIX}/sbin/iscsifs
	${INSTALL_MAN} ${WRKSRC}/src/iscsifs.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/iscsifs.8

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
