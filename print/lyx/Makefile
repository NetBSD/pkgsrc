# $NetBSD: Makefile,v 1.18 1999/05/24 20:39:47 tv Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.0.2
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
