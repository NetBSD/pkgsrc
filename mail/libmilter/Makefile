# $NetBSD: Makefile,v 1.3 2003/09/15 12:22:31 markd Exp $

.include "../../mail/sendmail/Makefile.common"

PKGNAME=	libmilter-${DIST_VERS}
PKGREVISION=	1
COMMENT=	Mail filter support library for sendmail

post-patch: make-sendmail-siteconfig
	${ECHO} >>${DESCR_SRC}

do-build:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build)

do-install:
	@(cd ${WRKSRC}/libmilter; ${SETENV} ${MAKE_ENV} ./Build INCLUDEDIR=${PREFIX}/include LIBDIR=${PREFIX}/lib install)

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`uname -srm | ${TR} \  .`
