# $NetBSD: Makefile,v 1.14 2001/07/02 21:54:19 jlam Exp $

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
.include "../../x11/lesstif/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
