# $NetBSD: Makefile,v 1.15 2002/03/17 21:44:46 markd Exp $
# FreeBSD Id: Makefile,v 1.9 1998/08/20 18:56:00 jseger Exp

DISTNAME=       povray31
PKGNAME=	povray-3.1g
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.povray.org/pub/povray/Official/Unix/ \
	 	ftp://www.hensa.ac.uk/mirrors/povray/povray/Official-3.0/Unix/\
		ftp://ftp.univ-lille1.fr/pub/povray/Official-3.0/Unix/
DISTFILES=      povuni_s.tgz povuni_d.tgz
DIST_SUBDIR=	${PKGNAME_NOREV}

MAINTAINER=	pooka@netbsd.org
HOMEPAGE=	http://www.povray.org/
COMMENT=	Persistence of Vision Ray Tracer

DEPENDS+=	png>=1.2.1:../../graphics/png

USE_X11=	yes

INSTALL_TARGET=	install-povray

.include "../../mk/bsd.pkg.mk"
