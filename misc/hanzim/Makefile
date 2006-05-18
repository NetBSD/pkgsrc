# $NetBSD: Makefile,v 1.3 2006/05/18 20:29:59 wiz Exp $
#

DISTNAME=	hanzim-1.3
PKGREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://kamares.ucsd.edu/~arobert/Files/Chinese/
EXTRACT_SUFX=	.tgz

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://zakros.ucsd.edu/~arobert/hanzim.html
COMMENT=	Chinese character learning-aid program

BROKEN_IN=	pkgsrc-2006Q1

WRKSRC=		${WRKDIR}/Hanzim

BUILD_TARGET=	hanzim

pre-install:
	@if [ "$$DISPLAY" = "" ]; then \
		${ECHO} "${DISTNAME} can only be installed under X11."; \
		exit 1; \
	 else \
		${SETENV} SHELL=${SH:Q}; export LC_CTYPE=en_US.ISO8859-1; \
	 fi

.include "../../lang/tcl/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
