# $NetBSD: Makefile,v 1.13 1999/11/23 16:42:01 dmcmahill Exp $
#
# IMPORTANT: Before upgrading this package, please read files/README.next_rev!

DISTNAME=	scilab-2.4.1-src
PKGNAME=	scilab-2.4.1
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www-rocq.inria.fr/scilab/

DEPENDS+=	xless-*:../../x11/xless
DEPENDS+=	pvm-3.4.2:../../parallel/pvm3

RESTRICTED=	"no paid distribution of SCILAB"
NO_CDROM=	${RESTRICTED}

USE_FORTRAN=	yes
USE_X11BASE=	yes
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

.include "../../mk/bsd.pkg.mk"
