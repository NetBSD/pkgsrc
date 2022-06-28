# $NetBSD: Makefile,v 1.3 2022/06/28 11:31:48 wiz Exp $

DISTNAME=	libvterm-0.1.4
PKGNAME=	${DISTNAME:S/libvterm/libvterm01/g}
PKGREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://www.leonerd.org.uk/code/libvterm/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.leonerd.org.uk/code/libvterm/
COMMENT=	Abstract VT220/xterm/ECMA-48 emulation library
LICENSE=	mit

USE_TOOLS+=	pkg-config gmake perl
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
	${MV} ${DESTDIR}${PREFIX}/lib/libvterm01/pkgconfig/vterm.pc \
	    ${DESTDIR}${PREFIX}/lib/pkgconfig/vterm01.pc

.include "../../mk/bsd.pkg.mk"
