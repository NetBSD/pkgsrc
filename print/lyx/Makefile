# $NetBSD: Makefile,v 1.26 2000/08/23 23:14:31 tron Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.1.2
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.lyx.org/

DEPENDS=		ispell-3.1.20:../../textproc/ispell
DEPENDS+=		teTeX>=1.0.6:../../print/teTeX
DEPENDS+=		xforms-0.88:../../x11/xforms

USE_PERL5=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS= 	--with-extra-lib="${X11BASE}/lib" \
			--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
