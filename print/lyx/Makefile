# $NetBSD: Makefile,v 1.47 2002/09/21 04:52:38 jlam Exp $
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

GCC_VERSION!=		gcc --version
.if (${GCC_VERSION:C/-.*$$//} == egcs)
# "egcs" cannot be used, as this package tickles c++ compiler bugs
.include "../../lang/gcc/Makefile.gcc"
.endif

USE_BUILDLINK2=		YES
USE_PERL5=		YES
GNU_CONFIGURE=		YES
CONFIGURE_ARGS+= 	--with-extra-lib=${BUILDLINK_PREFIX.xforms}/lib \
			--with-extra-inc=${BUILDLINK_PREFIX.xforms}/include/X11

USE_LIBTOOL=		YES
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
LIBTOOL_OVERRIDE+=	${WRKSRC}/sigc++/libtool

LDFLAGS+=		-L${X11BASE}/lib -Wl,-R${X11BASE}/lib

post-install:
	${CHMOD} +x ${PREFIX}/share/lyx/configure

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/xpm/buildlink2.mk"
.include "../../x11/xforms/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
