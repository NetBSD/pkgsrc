# $NetBSD: Makefile,v 1.11 1998/08/20 15:17:24 tsarna Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=	lyx-0.12.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://la1ad.uio.no/lyx/

BUILD_DEPENDS=	latex:../../print/teTeX
RUN_DEPENDS=	latex:../../print/teTeX \
		ispell:../../textproc/ispell
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	xforms-0.88:../../x11/xforms

ONLY_FOR_ARCHS=	arm32 i386 m68k sparc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

.include "../../mk/bsd.pkg.mk"
