# $NetBSD: Makefile,v 1.11 1998/10/02 22:52:48 tv Exp $
#

DISTNAME=		rsaref20
PKGNAME=		rsaref-2.0
WRKSRC=			${WRKDIR}/install
MAKEFILE=		unix/makefile
CATEGORIES=		security
MASTER_SITES=		${RSA_SITE}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		tv@netbsd.org
HOMEPAGE=		http://www.rsa.com/rsalabs/newfaq/q174.html

USE_LIBTOOL=		yes

RESTRICTED=		"Cryptographic source usable only within the USA"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		yes

ALL_TARGET=		librsaref.la

RSA_SITE=		ftp://ftp.rsa.com/rsaref/

# XXX time-dependent directory; can't give a sensible response
fetch-list:
	@${DO_NADA}

do-fetch:
	@if [ "X${USA_RESIDENT}" != XYES ]; then	\
		${ECHO} "This package is legal for use only within the United States."; \
		${ECHO} "You must set the variable USA_RESIDENT to YES to enable"; \
		${ECHO} "use of the rsaref package.";	\
	elif [ ! -f ${DISTDIR}/${DISTFILES} ]; then \
		${MKDIR} ${WRKDIR} || ${TRUE};  \
		${RM} -f ${WRKDIR}/README; \
		cd ${WRKDIR} && ${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${RSA_SITE}README ${FETCH_AFTER_ARGS} && \
		cd ${_DISTDIR} && ${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${RSA_SITE}`egrep '^dist/U\.S\.-only-' ${WRKDIR}/README`/${DISTNAME}${EXTRACT_SUFX} ${FETCH_AFTER_ARGS}; \
	fi

do-configure:
	@${RM} -f ${WRKDIR}/source/md5.h
	@${CP} ${FILESDIR}/md5.h ${WRKDIR}/source/
	@${LN} -sf . ${WRKDIR}/source/rsaref

do-install:
	${MKDIR} ${PREFIX}/include/rsaref ${PREFIX}/share/doc/rsaref
	cd ${WRKSRC} && \
		${LIBTOOL} --mode=install ${INSTALL_DATA} \
			librsaref.la ${PREFIX}/lib
	cd ${WRKDIR}/source && \
		${INSTALL_DATA} des.h global.h md2.h md5.h rsa.h rsaref.h \
			${PREFIX}/include/rsaref/
	cd ${WRKDIR}/doc && \
		${INSTALL_DATA} info.txt rsaref.txt ${PREFIX}/share/doc/rsaref/

.include "../../mk/bsd.pkg.mk"
