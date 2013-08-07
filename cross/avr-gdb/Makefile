# $NetBSD: Makefile,v 1.18 2013/08/07 05:34:14 mef Exp $

DISTNAME=	gdb-7.6
PKGNAME=	${DISTNAME:S/^/avr-/}
CATEGORIES=	cross
MASTER_SITES=	${MASTER_SITE_GNU:=gdb/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GNU gdb for Atmel AVR 8-bit RISC microcontrollers
LICENSE=	gnu-gpl-v3

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		CONFIG_LDFLAGS=${LDFLAGS:M*:Q}
CONFIGURE_ARGS+=	--target=avr
CONFIGURE_ARGS+=	--program-prefix=avr

INSTALLATION_DIRS=	bin
TEST_TARGET=		check

pre-configure:
	cd ${WRKSRC} ; ${RM} -rf dejagnu expect sim tcl texinfo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gdb/gdb ${DESTDIR}${PREFIX}/bin/avr-gdb

.include "../../mk/termcap.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
