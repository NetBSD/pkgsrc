# $NetBSD: Makefile,v 1.7 2004/08/06 16:31:09 uebayasi Exp $
# FreeBSD Id: ports/devel/avr-gdb/Makefile,v 1.2 2003/03/07 06:00:08 ade Exp

DISTNAME=	gdb-5.3
PKGNAME=	avr-gdb-5.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	karlj@mdstud.chalmers.se
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers

USE_GNU_TOOLS+=	make
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PKGNAME:C/-[^-]*$//}

.include "../../mk/bsd.pkg.mk"
