# $NetBSD: Makefile,v 1.34 2000/06/21 02:24:22 jlam Exp $
#

DISTNAME=		MesaLib-3.1
PKGNAME=		Mesa-3.1
CATEGORIES=		graphics
MASTER_SITES= 		ftp://ftp.mesa3d.org/mesa/ \
			http://download.sourceforge.net/mesa3d/
EXTRACT_SUFX=		.tar.bz2
# MesaDemos is needed for glut
DISTFILES=		MesaLib-3.1${EXTRACT_SUFX} \
			MesaDemos-3.1${EXTRACT_SUFX}

MAINTAINER=		mycroft@netbsd.org
HOMEPAGE=		http://www.ssec.wisc.edu/~brianp/Mesa.html

CONFLICTS=		Mesa-glx-*

WRKSRC=			${WRKDIR}/${PKGNAME}
USE_X11BASE=		# defined
USE_LIBTOOL=		# defined
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS=		--enable-static

.include "../../mk/bsd.pkg.mk"
