# $NetBSD: Makefile,v 1.2 2001/02/11 14:46:28 tron Exp $

DISTNAME=	${PKGNAME}-src
PKGNAME=	${PRG}-1.10
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	textproc converters
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=gutenpalm/}

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://gutenpalm.sourceforge.net/makeztxt.php

PRG=		makeztxt

do-build:
	cd ${WRKSRC} &&							\
	${CC} ${CFLAGS} -I. -o ${PRG} ${PRG}.c ${LDFLAGS} -lz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PRG} ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PRG}
.for doc in COPYING ChangeLog README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/${PRG}
.endfor

.include "../../mk/bsd.pkg.mk"
