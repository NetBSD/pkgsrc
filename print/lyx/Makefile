# $NetBSD: Makefile,v 1.35 2001/05/19 14:21:16 drochner Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.1.6fix1
CATEGORIES=		print
# XXX temporary: problems with the ftp server
#MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/
MASTER_SITES=		ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/

MAINTAINER=		frueauf@netbsd.org
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Graphical frontend for LaTeX (nearly WYSIWYG)

DEPENDS=		ispell-base-*:../../textproc/ispell-base
DEPENDS+=		teTeX>=1.0.6:../../print/teTeX
DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

USE_PERL5=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS= 	--with-extra-lib="${X11BASE}/lib" \
			--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

.include "../../mk/bsd.pkg.mk"
