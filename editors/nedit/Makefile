# $NetBSD: Makefile,v 1.9 2000/05/19 11:24:46 mjl Exp $

DISTNAME=	nedit-5.1.1-src
PKGNAME=	nedit-5.1.1
CATEGORIES=	editors
MASTER_SITES=	http://ftp.nedit.org/ftp/v5_1_1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nedit.org/

USE_MOTIF=	yes

NO_CONFIGURE=	yes
ALL_TARGET=	netbsd

WRKSRC=	${WRKDIR}/${PKGNAME}

do-install:
.for PROGRAM in nc nedit
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PROGRAM} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PROGRAM}.man ${PREFIX}/man/man1/${PROGRAM}.1
.endfor
	${MKDIR} ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nedit

.include "../../mk/bsd.pkg.mk"
