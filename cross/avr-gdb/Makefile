# $NetBSD: Makefile,v 1.10 2005/05/22 20:07:44 jlam Exp $

DISTNAME=	gdb-5.3
PKGNAME=	avr-gdb-5.3
PKGREVISION=	1
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	karlj@mdstud.chalmers.se
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers

USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--target=avr --program-prefix=avr

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb \
		${PREFIX}/bin/${PKGNAME:C/-[^-]*$//}

.include "../../mk/bsd.pkg.mk"
