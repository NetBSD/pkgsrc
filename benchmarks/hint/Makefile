# $NetBSD: Makefile,v 1.3 1998/12/03 01:27:05 hubertf Exp $
#
# New ports collection makefile for:	hint
# Version required:	12 June 1998 (no version stamp)
# Date created:		18 May 1998
# Whom:			ghelmer
#
# FreeBSD: Makefile,v 1.1.1.1 1998/06/15 18:09:43 ghelmer Exp
#

DISTNAME=	hint_unix_serial
PKGNAME=	hint.serial-98.06.12
CATEGORIES=	benchmarks
MASTER_SITES=	ftp://ftp.scl.ameslab.gov/pub/HINT/source/tar/
EXTRACT_SUFX=	.tar

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.scl.ameslab.gov/Projects/HINT/

EXTRACT_BEFORE_ARGS=-xf
WRKSRC=		${WRKDIR}/unix
ALL_TARGET=	DOUBLE

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/DOUBLE ${PREFIX}/bin/hint
	${INSTALL_MAN} ${WRKSRC}/hint.1 ${PREFIX}/man/man1

benchmark:
	cd ${WRKSRC} ; mkdir -p data ; ./DOUBLE

.include "../../mk/bsd.pkg.mk"
