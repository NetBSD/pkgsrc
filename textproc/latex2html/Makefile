# $NetBSD: Makefile,v 1.2 2000/11/03 01:05:06 jlam Exp $

DISTNAME=	latex2html-99.2beta8
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=support/latex2html/}

MAINTAINER=	wennmach@netbsd.org
HOMEPAGE=	http://www-dsed.llnl.gov/files/programs/unix/latex2html/manual/

DEPENDS+=       teTeX-bin>=1.0.6:../../print/teTeX-bin
DEPENDS+=	ghostscript{,-nox11}-[6-9]*:../../print/ghostscript
DEPENDS+=	netpbm>=9.7:../../graphics/netpbm

USE_PERL5=		# defined
GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--enable-gif	# add support of GIF images
CONFIGURE_ARGS+=	--enable-png	# add support of PNG images
CONFIGURE_ARGS+=	--with-texpath=${PREFIX}/share/texmf/tex/latex/html

# We don't need the following post-install target because during installation
# after a build, mktexlsr is called correctly.  If the INSTALL script should
# ever change to do more than simply call mktexlsr, then the post-install
# target should be uncommented.
#
# post-install:
#	PKG_PREFIX=${PREFIX} ${SH} ${INSTALL_FILE} ${PKGNAME} POST-INSTALL

.include "../../mk/bsd.pkg.mk"
