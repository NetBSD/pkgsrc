# $NetBSD: Makefile,v 1.7 1998/04/24 09:20:37 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=	lyx-0.12.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/

MAINTAINER=	frueauf@netbsd.org

BUILD_DEPENDS=	latex:../../print/teTeX
RUN_DEPENDS=	latex:../../print/teTeX \
		ispell:../../textproc/ispell
DEPENDS+=	xpm-3.4j:../../graphics/xpm
DEPENDS+=	xforms-0.88:../../x11/xforms

ONLY_FOR_ARCHS=	arm32 i386 m68k sparc

GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib --with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

MAN1=		lyx.1

.include "../../mk/bsd.pkg.mk"
