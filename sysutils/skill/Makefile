# $NetBSD: Makefile,v 1.16 2003/09/23 13:58:36 wiz Exp $
#

DISTNAME=	skill-4.1
PKGREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	ftp://fast.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://www.cs.utah.edu/~forys/software.html
COMMENT=	Signal processes given user names, ttys, commands, or pids

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	OSTYPE=nbsd-44
.elif ${OPSYS} == "SunOS"
BINMODE=	02555
MAKE_ENV+=	OSTYPE=sys-5r4 BINGRP=sys CPPFLAGS=
.endif

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skill ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skill.1 ${PREFIX}/man/man1
	${RM} -f ${PREFIX}/bin/snice ${PREFIX}/man/man1/snice.1
	${LN} -s skill ${PREFIX}/bin/snice
	${LN} -s skill.1 ${PREFIX}/man/man1/snice.1

.include "../../mk/bsd.pkg.mk"
