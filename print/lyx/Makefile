# $NetBSD: Makefile,v 1.40 2002/01/18 11:02:32 martti Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.1.6fix4
PKGNAME=		lyx-1.1.6.4
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/

MAINTAINER=		martti@netbsd.org
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Graphical frontend for LaTeX (nearly WYSIWYG)

DEPENDS=		ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=		teTeX>=1.0.6:../../print/teTeX
DEPENDS+=		xforms>=0.88nb1:../../x11/xforms

USE_PERL5=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS= 	--with-extra-lib="${X11BASE}/lib" \
			--with-extra-inc="${X11BASE}/include ${X11BASE}/include/X11"

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

post-configure:
	${MV} ${WRKSRC}/po/Makefile ${WRKSRC}/po/Makefile.orig
	${SED} '/^datadir/s/lib/share/g' \
		< ${WRKSRC}/po/Makefile.orig > ${WRKSRC}/po/Makefile

post-install:
	${CHMOD} +x ${PREFIX}/share/lyx/configure

.include "../../mk/bsd.pkg.mk"
