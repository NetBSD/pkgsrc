# $NetBSD: Makefile,v 1.24 2000/02/15 09:26:23 agc Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.1.2
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.lyx.org/

DEPENDS=		ispell-3.1.20:../../textproc/ispell
DEPENDS+=		teTeX-1.0.6:../../print/teTeX
DEPENDS+=		xpm-3.4k:../../graphics/xpm
DEPENDS+=		xforms-0.88:../../x11/xforms

USE_PERL5=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS= 	--with-extra-lib="${X11BASE}/lib" \
			--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
