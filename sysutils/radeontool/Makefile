# $NetBSD: Makefile,v 1.11 2026/08/04 20:29:16 wiz Exp $

DISTNAME=	radeontool-1.5
PKGREVISION=	5
CATEGORIES=	sysutils
MASTER_SITES=	http://fdd.com/software/radeon/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fdd.com/software/radeon/
COMMENT=	Toggle backlight and external video output on Radeon cards

BUILD_TARGET=		radeontool
INSTALLATION_DIRS=	sbin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/radeontool ${DESTDIR}${PREFIX}/sbin

# FIXME: replace by proper LDFLAGS handling
_WRAP_EXTRA_ARGS.CC+=	${_RELRO_LDFLAGS}
_WRAP_EXTRA_ARGS.CXX+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cc+=	${_RELRO_LDFLAGS}
CWRAPPERS_PREPEND.cxx+=	${_RELRO_LDFLAGS}

.include "../../sysutils/pciutils/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
