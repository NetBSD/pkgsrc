# $NetBSD: Makefile,v 1.1.1.1 2003/09/21 16:17:42 kim Exp $
#

DISTNAME=	Image-Imlib2-0.12
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5im2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Image/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/Image-Imlib2/
COMMENT=	Interface to the Imlib2 image library

DEPENDS+=	p5-Module-Build-[0-9]*:../../devel/p5-Module-Build

USE_PERL5=	run
USE_X11=	YES
USE_BUILDLINK2=	YES

# If the X11 and Xext libraries are not weeded out,
# they will be unresolved in the resulting .so

IMLIB2LIBS=	$$CONFIG --libs | ${SED} -e 's/-lX11//g' -e 's/-lXext//g'

post-patch:
	cd ${WRKSRC} && \
	${SED} -e 's,@IMLIB2LIBS@,${IMLIB2LIBS},' Build.PL > Build.PL.new && \
	${MV} -f Build.PL.new Build.PL

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PERL5} Build.PL

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build

do-test:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build test

do-install:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ./Build install


.include "../../graphics/imlib2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
