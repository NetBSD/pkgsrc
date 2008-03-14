# $NetBSD: Makefile,v 1.15 2008/03/14 02:56:10 jnemeth Exp $

PKGNAME=	libmilter-${DIST_VERS}
PKGREVISION=	1
COMMENT=	Mail filter support library for sendmail

PKG_DESTDIR_SUPPORT=	user-destdir

.include "options.mk"
.include "../../mail/sendmail/Makefile.common"

INSTALLATION_DIRS=	include lib

post-patch: make-sendmail-siteconfig

do-build:
	(cd ${WRKSRC}/libmilter && env ${MAKE_ENV} ./Build)

do-install:
	(cd ${WRKSRC}/libmilter && env ${MAKE_ENV} ./Build BINOWN=${BINOWN:Q} BINGRP=${BINGRP:Q} SHAREOWN=${SHAREOWN:Q} SHAREGRP=${SHAREGRP:Q} INCLUDEDIR=${DESTDIR:Q}${PREFIX}/include LIBDIR=${DESTDIR:Q}${PREFIX}/lib install)

PTHREAD_OPTS+=	require

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"

# has to be below include for bsd.pkg.mk, else substition fails
OBJDIR!=	${ECHO} obj.`${UNAME} -srm | ${TR} \  .`
