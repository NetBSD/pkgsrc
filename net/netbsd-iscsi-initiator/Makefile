# $NetBSD: Makefile,v 1.1.1.1 2010/06/04 16:07:51 sborrill Exp $

DISTNAME=	netbsd-iscsi-20080207
PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-initiator/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_BACKUP}

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	NetBSD's iSCSI initiator (per iSCSI RFC 3720)

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src
BUILD_TARGET=	all-initiator

AUTO_MKDIRS=			yes

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/iscsifs ${DESTDIR}${PREFIX}/sbin/iscsifs
	${INSTALL_MAN} ${WRKSRC}/src/iscsifs.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/iscsifs.8

.include "../../mk/fuse.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
