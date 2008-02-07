# $NetBSD: Makefile,v 1.8 2008/02/07 19:31:51 agc Exp $

DISTNAME=	netbsd-iscsi-20080207
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
