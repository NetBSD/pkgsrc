# $NetBSD: Makefile,v 1.28 2001/11/29 01:12:41 hubertf Exp $
#

DISTNAME=	${SCIBASE}.src
PKGNAME=	${SCIBASE}
PKGREVISION=	1
SCIBASE=	scilab-2.6
WRKSRC=		${WRKDIR}/${DISTNAME:.src=}
CATEGORIES=	math
MASTER_SITES=	ftp://ftp.inria.fr/INRIA/Projects/Meta2/Scilab/distributions/

MAINTAINER=	dmcmahill@netbsd.org
HOMEPAGE=	http://www-rocq.inria.fr/scilab/
COMMENT=	High-level scientific math programming environment with graphics

DEPENDS+=	xless-[0-9]*:../../x11/xless
DEPENDS+=	pvm-3.4.3:../../parallel/pvm3

# needs full floating point math.  Once the FPC code for alpha is integrated
# this line can be changed to only exclude older versions of the operating
# system.  Additionally, -mieee will need to be added.
NOT_FOR_PLATFORM=	*-*-alpha

USE_FORTRAN=		yes
USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/config/ltconfig
USE_X11BASE=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--without-xless --with-xaw
#override HOME to avoid picking up a bad ${HOME}/.scilab during the build
MAKE_ENV+=	HOME=${WRKSRC} PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=	LOCALBASE=${LOCALBASE}
PVM_ROOT?=	${LOCALBASE}/pvm3
CONFIGURE_ENV+=	PVM_ROOT=${PVM_ROOT}
CONFIGURE_ENV+=	X11BASE=${X11BASE}
PLIST_SUBST+=	SCIBASE=${SCIBASE}

# remove some stuff which is broken in the distfile.  The config's
# are links to ../config (ie circular).
post-extract:
	${RM} -f ${WRKSRC}/examples/callsci/callsciJava/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciFortran/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciC/config/config
	${RM} -f ${WRKSRC}/examples/callsci/callsciC++/config/config

# clean up any possible leftovers from 'make test' so that our PLIST
# will still be right
pre-install:
	cd ${WRKSRC}/tests && ${MAKE_PROGRAM} distclean
	cd ${WRKSRC}/examples && ${MAKE_PROGRAM} distclean

post-install:
	${LN} -sf ${X11PREFIX}/bin/xless ${PREFIX}/${SCIBASE}/bin/xless

# the "SCI=0 && unset SCI" is done because some of the tests really will
# fail if SCI is set to anything.
test: build
	SCI=0 && unset SCI && cd ${WRKSRC}/tests && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		 tee ${WRKDIR}/tests.log
	SCI=0 && unset SCI && cd ${WRKSRC}/examples && \
		${MAKE_ENV} ${MAKE_PROGRAM} tests 2>&1 | \
		tee ${WRKDIR}/examples.log

.include "../../mk/bsd.pkg.mk"
