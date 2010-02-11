# $NetBSD: Makefile,v 1.32 2010/02/11 22:47:49 joerg Exp $
#

DISTNAME=		sniffit.0.3.5
PKGNAME=		sniffit-0.3.5
PKGREVISION=		2
CATEGORIES=		net security
MASTER_SITES=		http://reptile.rug.ac.be/~coder/sniffit/files/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://reptile.rug.ac.be/~coder/sniffit/sniffit.html
COMMENT=		Packet sniffer program

PKG_DESTDIR_SUPPORT=	user-destdir

NOT_FOR_PLATFORM=	*-*-alpha	# severe LP64 loss

GNU_CONFIGURE=		YES
BUILD_TARGET=
INSTALLATION_DIRS=	${PKGMANDIR}/man5 ${PKGMANDIR}/man8 sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/sniffit ${DESTDIR}${PREFIX}/sbin/sniffit
	${INSTALL_MAN}     ${WRKSRC}/sniffit.5 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man5
	${INSTALL_MAN}     ${WRKSRC}/sniffit.8 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man8

.include "../../devel/ncurses/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
