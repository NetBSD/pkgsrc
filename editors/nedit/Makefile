# $NetBSD: Makefile,v 1.15 2001/09/08 19:55:42 jlam Exp $

DISTNAME=	nedit-5.1.1-src
PKGNAME=	nedit-5.1.1
CATEGORIES=	editors
MASTER_SITES=	http://ftp.nedit.org/ftp/v5_1_1/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nedit.org/
COMMENT=	Motif based standard GUI style text editor

USE_BUILDLINK_ONLY=	YES
ALL_TARGET=		netbsd

CFLAGS+=	-I${X11BASE}/include

WRKSRC=	${WRKDIR}/${PKGNAME}

do-install:
.for PROGRAM in nc nedit
	${INSTALL_PROGRAM} ${WRKSRC}/source/${PROGRAM} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PROGRAM}.man ${PREFIX}/man/man1/${PROGRAM}.1
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/nedit
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/nedit

.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
