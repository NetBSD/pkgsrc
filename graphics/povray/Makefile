# $NetBSD: Makefile,v 1.17 2003/07/17 21:42:24 grant Exp $
# FreeBSD Id: Makefile,v 1.9 1998/08/20 18:56:00 jseger Exp

DISTNAME=       povray31
PKGNAME=	povray-3.1g
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Old-Versions/Official-3.1g/Unix/\
	 	ftp://ftp.mirror.ac.uk/sites/ftp.povray.org/pub/povray/Old-Versions/Official-3.1g/Unix/
DISTFILES=      povuni_s.tgz povuni_d.tgz

MAINTAINER=	pooka@NetBSD.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer

DEPENDS+=	png>=1.2.1:../../graphics/png

DIST_SUBDIR=	${PKGNAME_NOREV}
USE_X11=	yes

INSTALL_TARGET=	install-povray

.include "../../mk/bsd.pkg.mk"
