# $NetBSD: Makefile,v 1.11 2001/02/17 17:42:18 wiz Exp $
#
# The version number for skill does not match the @P number.
# This is normal.

DISTNAME=	skill-4.0
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://fast.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
COMMENT=	Signal processes given user names, ttys, commands, or pids

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	OSTYPE=bsd-44
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
