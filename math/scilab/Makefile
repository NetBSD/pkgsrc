# $NetBSD: Makefile,v 1.9 1999/08/06 13:45:51 agc Exp $
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

PLIST_SRC=      ${WRKDIR}/.PLIST-src

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
	@${SED} -e 's|@localbase@|'${LOCALBASE}'|g' \
                -e 's|@x11base@|'${X11BASE}'|g' < ${PKGDIR}/PLIST > ${PLIST_SRC}
	@if [ ${MACHINE_ARCH} != "alpha" ]; then \
		${MV} ${WRKSRC}/scilab.star.orig ${WRKSRC}/scilab.star ; \
	fi

.include "../../mk/bsd.pkg.mk"
