# $NetBSD: Makefile,v 1.23 1999/02/17 02:46:47 hubertf Exp $
# FreeBSD Id: Makefile,v 1.2 1997/11/05 23:55:31 asami Exp
#

DISTNAME=	cdrecord-1.6.1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.fokus.gmd.de/pub/unix/cdrecord/

MAINTAINER=	hubertf@netbsd.org
HOMEPAGE=	http://www.fokus.gmd.de/nthp/employees/schilling/cdrecord.html

CONFLICTS=	cdrecord-*

USE_GMAKE=	yes

post-configure:
	cd ${WRKSRC}/RULES ; [ -f netbsd-cc.rul ] || ${MV} i386-netbsd-cc.rul netbsd-cc.rul
	cd ${WRKSRC}/RULES ; [ -f netbsd-gcc.rul ] || ${MV} i386-netbsd-gcc.rul netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ${LN} -sf netbsd-gcc.rul ${MACHINE}-netbsd-gcc.rul
	cd ${WRKSRC}/RULES ; ${LN} -sf netbsd-cc.rul ${MACHINE}-netbsd-cc.rul

do-build:
	@cd ${WRKSRC}/lib && ../Gmake PREFIX=${PREFIX}
	@cd ${WRKSRC}/cdrecord && ../Gmake PREFIX=${PREFIX}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${MACHINE}-netbsd-cc/cdrecord \
	 ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@[ -e /dev/su0-6-0 ] || ${LN} -fs /dev/cd0d /dev/su0-6-0

.include "../../mk/bsd.pkg.mk"
