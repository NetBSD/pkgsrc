# $NetBSD: Makefile,v 1.9 2007/03/24 19:21:27 joerg Exp $

.include "../../mail/sendmail/Makefile.common"

PKGNAME=	libmilter-${DIST_VERS}
COMMENT=	Mail filter support library for sendmail

INSTALLATION_DIRS=	lib

post-patch: make-sendmail-siteconfig

do-build:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib install)

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | ${TR} \  .`
