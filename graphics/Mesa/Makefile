# $NetBSD: Makefile,v 1.31 2000/04/04 07:59:48 tron Exp $
#

DISTNAME=       MesaLib-3.1
PKGNAME=	Mesa-3.1
CATEGORIES=	graphics
MASTER_SITES= 	ftp://ftp.mesa3d.org/mesa/ \
		http://download.sourceforge.net/mesa3d/
# MesaDemos is needed for glut
DISTFILES=	MesaLib-3.1.tar.bz2 \
		MesaDemos-3.1.tar.bz2

MAINTAINER=	mycroft@netbsd.org
HOMEPAGE=	http://www.ssec.wisc.edu/~brianp/Mesa.html

CONFLICTS=	Mesa-glx-*

WRKSRC=         ${WRKDIR}/${PKGNAME}
USE_X11BASE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-static
# XXX our pkglibtool is too old
#USE_LIBTOOL=	yes

.include "../../mk/bsd.pkg.mk"
