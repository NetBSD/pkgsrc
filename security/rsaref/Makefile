# New ports collection makefile for: rsaref
# Version required:     2.0
# Date created:         17 Feb 1998
# Whom:                 tv@netbsd.org
#
# $NetBSD: Makefile,v 1.5 1998/04/12 22:03:05 tv Exp $
#

DISTNAME=		rsaref20
PKGNAME=		rsaref-2.0
WRKSRC=			${WRKDIR}/source
CATEGORIES=		security
RSA_SITE=		ftp://ftp.rsa.com/rsaref/
MASTER_SITES=		${RSA_SITE}
EXTRACT_SUFX=		.tar.Z

MAINTAINER=		packages@NetBSD.ORG

RESTRICTED=		"Cryptographic source usable only within the USA"
MIRROR_DISTFILE=	no
IS_INTERACTIVE=		yes

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
		cd ${WRKDIR} && ${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${RSA_SITE}README ${FETCH_AFTER_ARGS}; \
		cd ${_DISTDIR} && ${FETCH_CMD} ${FETCH_BEFORE_ARGS} ${RSA_SITE}`egrep '^dist/U\.S\.-only-' ${WRKDIR}/README`/${DISTNAME}${EXTRACT_SUFX} ${FETCH_AFTER_ARGS}; \
	fi

pre-configure:
	@${RM} -f ${WRKSRC}/md5.h
	@${CP} ${FILESDIR}/Makefile ${FILESDIR}/md5.h ${WRKSRC}
	@${LN} -s . ${WRKSRC}/rsaref

do-install:
	${MKDIR} ${PREFIX}/include/rsaref ${PREFIX}/share/doc/rsaref
	cd ${WRKSRC} && \
		${INSTALL_DATA} des.h global.h md2.h md5.h rsa.h rsaref.h \
			${PREFIX}/include/rsaref
	cd ${WRKSRC} && \
		${INSTALL_DATA} librsaref.a librsaref.so.2.0 ${PREFIX}/lib
	${LN} -sf librsaref.so.2.0 ${PREFIX}/lib/librsaref.so.2
	${LN} -sf librsaref.so.2.0 ${PREFIX}/lib/librsaref.so
	${LDCONFIG} || ${TRUE}
	cd ${WRKDIR}/doc && \
		${INSTALL_DATA} info.txt rsaref.txt ${PREFIX}/share/doc/rsaref

.include <bsd.port.mk>
