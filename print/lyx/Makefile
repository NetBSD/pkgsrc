# $NetBSD: Makefile,v 1.13 1998/11/19 15:40:46 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=	lyx-0.12.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://la1ad.uio.no/lyx/

DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	xforms-0.88:../../x11/xforms
DEPENDS+=	teTeX-0.4p8:../../print/teTeX
DEPENDS+=	ispell-3.1.20:../../textproc/ispell

ONLY_FOR_ARCHS=	arm32 i386 m68k sparc ns32k

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

.include "../../mk/bsd.pkg.mk"
