# $NetBSD: Makefile,v 1.1 1998/07/31 08:03:09 tron Exp $

DISTNAME=		xevil1.5.1e
PKGNAME=		xevil-1.5.1e
CATEGORIES=		games x11
MASTER_SITES=		ftp://ftp.xevil.com/xevil1.5.1e/
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		root@garbled.net

NO_WRKSUBDIR=		yes
MAKE_ENV=		HOSTTYPE="netbsd" \
			INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_MAN="${INSTALL_MAN}"

USE_X11=		yes

.include "../../mk/bsd.pkg.mk"
.if (${OBJECT_FMT} == "ELF")
RPATH=		-Wl,-R,${PREFIX}/lib
.endif
MAKE_ENV+=	RPATH=${RPATH}
