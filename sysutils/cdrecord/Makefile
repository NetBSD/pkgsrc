# $NetBSD: Makefile,v 1.15 1998/06/22 13:09:50 agc Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 23:55:31 asami Exp
#

DISTNAME=	cdrecord-1.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	hubertf@NetBSD.org

RUN_DEPENDS=	mkisofs:../../sysutils/mkisofs

USE_GMAKE=	yes

post-configure:
	cd ${WRKSRC}/RULES ; [ -f netbsd-cc.rul ] || ${MV} i386-netbsd-cc.rul netbsd-cc.rul
	cd ${WRKSRC}/RULES ; [ -f netbsd-gcc.rul ] || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ${LN} -sf netbsd-gcc.rul ${ARCH}-netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ${LN} -sf netbsd-cc.rul ${ARCH}-netbsd-cc.rul

do-build:
	@cd ${WRKSRC}/lib && ../Gmake PREFIX=${PREFIX}
	@cd ${WRKSRC}/cdrecord && ../Gmake PREFIX=${PREFIX}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${ARCH}-netbsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@[ -e /dev/scgx ] || ${LN} -fs /dev/cd0d /dev/scgx
	@${CAT} ${PKGDIR}/MESSAGE

.include "../../mk/bsd.pkg.mk"
