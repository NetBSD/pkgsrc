# $NetBSD: Makefile,v 1.15 2009/12/12 22:14:34 asau Exp $

DISTNAME=		dfftpack-20001209
PKGREVISION=		2
CATEGORIES=		math
MASTER_SITES=		${MASTER_SITE_LOCAL}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Double precision version of FFTPACK

NO_SRC_ON_FTP=		Already in MASTER_SITE_LOCAL
USE_LANGUAGES=		fortran
WRKSRC=			${WRKDIR}/dfftpack

PKG_DESTDIR_SUPPORT=	user-destdir
INSTALLATION_DIRS=	lib share/doc/dfftpack share/examples/dfftpack

post-extract:
	${CP} ${FILESDIR}/Makefile ${WRKSRC}

post-install:
	@for f in README doc doc.double ; do \
	${INSTALL_DATA} ${WRKSRC}/$$f ${DESTDIR}${PREFIX}/share/doc/dfftpack ; done
	${INSTALL_DATA} ${WRKSRC}/test.f ${DESTDIR}${PREFIX}/share/examples/dfftpack

.include "../../mk/bsd.pkg.mk"
