# $NetBSD: Makefile,v 1.46 2002/08/23 09:08:08 martti Exp $
# FreeBSD Id: Makefile,v 1.14 1998/02/14 16:46:50 andreas Exp
#

DISTNAME=		lyx-1.2.1
PKGNAME=		lyx-1.2.1
CATEGORIES=		print
MASTER_SITES=		ftp://ftp.lyx.org/pub/lyx/stable/ \
			ftp://gd.tuwien.ac.at/publishing/tex/lyx/stable/ \
			ftp://ftp.sdsc.edu/pub/other/lyx/stable/

MAINTAINER=		martti@netbsd.org
HOMEPAGE=		http://www.lyx.org/
COMMENT=		Graphical frontend for LaTeX (nearly WYSIWYG)

DEPENDS=		ispell-base-[0-9]*:../../textproc/ispell-base
DEPENDS+=		teTeX>=1.0.6:../../print/teTeX
DEPENDS+=		jpeg-6b:../../graphics/jpeg
DEPENDS+=		xforms>=0.9999:../../x11/xforms

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.include "../../lang/gcc/Makefile.gcc"
.endif

USE_PERL5=		YES
USE_XPM=		YES
GNU_CONFIGURE=		YES
EVAL_PREFIX+=		XFORMSDIR=xforms
CONFIGURE_ARGS+= 	--with-extra-lib="${X11BASE}/lib" \
			--with-extra-inc="${XFORMSDIR}/include/X11"

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

post-install:
	${CHMOD} +x ${PREFIX}/share/lyx/configure

.include "../../mk/bsd.pkg.mk"
