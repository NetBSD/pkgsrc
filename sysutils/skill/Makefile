# $NetBSD: Makefile,v 1.4 1999/09/27 13:28:56 agc Exp $
#
# The version number for skill does not match the @P number.
# This is normal.

DISTNAME=	skill-3.7@P6
PKGNAME=	skill-3.7.7
WRKSRC=		${WRKDIR}/${PKGNAME}
CATEGORIES=	sysutils
MASTER_SITES=	ftp://fast.cs.utah.edu/pub/skill/
EXTRACT_SUFX=	_tar.Z

MAINTAINER=	kim@tac.nyc.ny.us

BINMODE=	02555

.include "../../mk/bsd.prefs.mk"

MAKE_ENV+=	UVM=${UVM}

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	OSTYPE=bsd-4.4 BINGRP=kmem
.elif ${OPSYS} == "SunOS"
MAKE_ENV+=	OSTYPE=sys-5r4 BINGRP=sys CPPFLAGS=
.endif

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skill ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skill.1 ${PREFIX}/man/man1
	${RM} -f ${PREFIX}/bin/snice ${PREFIX}/man/man1/snice.1
	${LN} -s skill ${PREFIX}/bin/snice
	${LN} -s skill.1 ${PREFIX}/man/man1/snice.1

.include "../../mk/bsd.pkg.mk"
