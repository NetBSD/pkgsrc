# $NetBSD: Makefile,v 1.19 1999/06/04 06:00:10 frueauf Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.0.3
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.via.ecp.fr/pub/lyx/stable/ \
			ftp://la1ad.uio.no/pub/lyx/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://la1ad.uio.no/lyx/

DEPENDS=		ispell-3.1.20:../../textproc/ispell \
			teTeX-0.4p8:../../print/teTeX \
			xpm-3.4k:../../graphics/xpm \
			xforms-0.88:../../x11/xforms

USE_PERL5=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--with-extra-lib=${X11BASE}/lib \
			--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

.include "../../mk/bsd.pkg.mk"
