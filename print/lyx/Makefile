# $NetBSD: Makefile,v 1.14 1999/02/03 17:24:22 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=	lyx-1.0.0
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
		ftp://la1ad.uio.no/pub/lyx/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://la1ad.uio.no/lyx/

DEPENDS+=	ispell-3.1.20:../../textproc/ispell
DEPENDS+=	teTeX-0.4p8:../../print/teTeX
DEPENDS+=	xpm-3.4k:../../graphics/xpm
DEPENDS+=	xforms-0.88:../../x11/xforms

CONFLICTS=	lyx-*

# restrictions from xforms
ONLY_FOR_ARCHS=	arm32 i386 m68k sparc ns32k

USE_PERL5=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-extra-lib=${X11BASE}/lib \
		--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

.include "../../mk/bsd.pkg.mk"
