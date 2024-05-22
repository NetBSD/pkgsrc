# $NetBSD: Makefile,v 1.2 2024/05/22 19:49:44 leot Exp $

DISTNAME=	libvterm-0.3.3
PKGNAME=	${DISTNAME:S/libvterm/libvterm03/g}
CATEGORIES=	devel
MASTER_SITES=	https://www.leonerd.org.uk/code/libvterm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.leonerd.org.uk/code/libvterm/
COMMENT=	Abstract VT220/xterm/ECMA-48 emulation library
LICENSE=	mit

USE_TOOLS+=	gmake perl
USE_LIBTOOL=	yes

MAKE_FLAGS+=	PREFIX=${PREFIX}
MAKE_FLAGS+=	INCDIR=${PREFIX}/include/${PKGBASE}
MAKE_FLAGS+=	LIBDIR=${PREFIX}/lib/${PKGBASE}

# Do not install programs, in case we conflict with a
# package for a more recent version.
INSTALL_TARGET=	install-lib install-inc

PKGCONFIG_OVERRIDE+=	vterm.pc.in

INSTALLATION_DIRS+=	lib/pkgconfig

post-install:
	${MV} ${DESTDIR}${PREFIX}/lib/libvterm03/pkgconfig/vterm.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/vterm03.pc

.include "../../mk/bsd.pkg.mk"
