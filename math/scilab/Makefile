# $NetBSD: Makefile,v 1.6 1999/03/05 11:22:34 frueauf Exp $
#
# IMPORTANT: Before upgrading this package, please read files/README.next_rev!

DISTNAME=	scilab-2.4.1-src
PKGNAME=	scilab-2.4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/

MAINTAINER=	mcmahill@alum.mit.edu
HOMEPAGE=	http://www-rocq.inria.fr/scilab/

.if !exists(/usr/bin/fort77)
DEPENDS+=	f2c-19980913:../../lang/f2c
.endif
DEPENDS+=	xless-1.7:../../x11/xless
DEPENDS+=	pvm-3.4.7:../../parallel/pvm3

NO_CDROM=	"no paid distribution of SCILAB"
RESTRICTED=	"no paid distribution of SCILAB"

USE_X11=	yes
GNU_CONFIGURE=	yes

MAKE_ENV+=	HOME=${WRKSRC}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
CONFIGURE_ENV+=	X11BASE=${X11BASE}

pre-fetch:
	@if [ ${MACHINE_ARCH} = "alpha" ]; then \
	${ECHO} "Although Scilab will build and run on the alpha, it sometimes" ; \
	${ECHO} "experiences floating point exceptions.  This problem is being" ; \
	${ECHO} "worked on and will be fixed as soon as possible.  However, the" ; \
	${ECHO} "program is still usable for many things." ; \
	fi

post-patch:
	@if [ ${MACHINE_ARCH} != "alpha" ]; then \
	${MV} ${WRKSRC}/scilab.star.orig ${WRKSRC}/scilab.star ; \
	fi

post-install:
	@${ECHO} "******************************************************************************"
	@${ECHO} "0 - COPYRIGHT NOTICE"
	@${ECHO} " "
	@${ECHO} "To use Scilab, you need to fill and return the end of the file notice.tex"
	@${ECHO} "or notice.ps (postscript file). You may email to Scilab@inria.fr."
	@${ECHO} "These files are in ${PREFIX}/share/scilab-2.4.1/"
	@${ECHO} "******************************************************************************"

.include "../../mk/bsd.pkg.mk"
