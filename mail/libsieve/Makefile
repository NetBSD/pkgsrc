# $NetBSD: Makefile,v 1.3 2004/01/20 12:19:43 agc Exp $
#

DISTNAME=	cyrus-imapd-2.1.12
PKGNAME=	${DISTNAME:S/cyrus-imapd/libsieve/}
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.andrew.cmu.edu/pub/cyrus-mail/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.cyrusoft.com/sieve/
COMMENT=	RFC3028 sieve library

WRKSRC=		${WRKDIR}/${DISTNAME}/sieve
USE_BUILDLINK2=	YES
USE_LIBTOOL=	YES
CPPFLAGS+=	-I.
CPPFLAGS+=	-I${PREFIX}/include/cyrus
LDFLAGS+=	-lcyrus

do-configure:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC} &&							\
	${LIBTOOL} --mode=install ${INSTALL_DATA} libsieve.la ${PREFIX}/lib
	${INSTALL_DATA_DIR} ${PREFIX}/include/sieve
.for hdr in sieve_err.h sieve_interface.h
	${INSTALL_DATA} ${WRKSRC}/${hdr} ${PREFIX}/include/sieve
.endfor

.include "../../mail/cyrus-imapd/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
