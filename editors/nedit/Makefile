# $NetBSD: Makefile,v 1.12 2001/02/16 14:40:52 wiz Exp $

DISTNAME=	nedit-5.1.1-src
PKGNAME=	nedit-5.1.1
CATEGORIES=	editors
MASTER_SITES=	http://ftp.nedit.org/ftp/v5_1_1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

USE_MOTIF=	YES
USE_XPM=	YES

NO_CONFIGURE=	YES
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
