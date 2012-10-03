# $NetBSD: Makefile,v 1.17 2012/10/03 00:10:29 asau Exp $

DISTNAME=	gdb-5.3
PKGNAME=	avr-gdb-5.3
PKGREVISION=	3
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--program-prefix=avr

INSTALLATION_DIRS=	bin

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${DESTDIR}${PREFIX}/bin/avr-gdb

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
