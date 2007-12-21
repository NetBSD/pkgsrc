# $NetBSD: Makefile,v 1.7 2007/12/21 13:26:43 agc Exp $

DISTNAME=	netbsd-iscsi-20071221
PKGNAME=	${DISTNAME:C/-iscsi/-iscsi-target/}
CATEGORIES=	devel
MASTER_SITES=	http://www.alistaircrooks.co.uk/src/

MAINTAINER=	agc@NetBSD.org
HOMEPAGE=	http://www.alistaircrooks.co.uk/software.html
COMMENT=	NetBSD's iSCSI target (per iSCSI RFC 3720)

CONFLICTS+=	netbsd-iscsi>0

GNU_CONFIGURE=	yes
CONFIGURE_DIRS=	src

INSTALLATION_DIRS_FROM_PLIST=yes

PKG_DESTDIR_SUPPORT=	user-destdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/iscsi-target ${DESTDIR}${PREFIX}/sbin/iscsi-target
	${INSTALL_DATA} ${WRKSRC}/doc/FAQ ${DESTDIR}${PREFIX}/share/doc/iscsi/FAQ
	${INSTALL_MAN} ${WRKSRC}/src/iscsi-target.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8/iscsi-target.8
	${INSTALL_MAN} ${WRKSRC}/src/targets.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/targets.5

.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
