# $NetBSD: Makefile,v 1.1.1.1 2003/07/16 22:11:31 wennmach Exp $
# FreeBSD Id: ports/devel/avr-gdb/Makefile,v 1.2 2003/03/07 06:00:08 ade Exp

DISTNAME=	gdb-5.2.1
PKGNAME=	avr-gdb-5.2.1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_SOURCEWARE:=gdb/releases/}

MAINTAINER=	karlj@mdstud.chalmers.se
COMMENT=	GNU GDB 5.2.1 for Atmel AVR microcontrollers

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PKGNAME:C/-[^-]*$//}

.include "../../mk/bsd.pkg.mk"
