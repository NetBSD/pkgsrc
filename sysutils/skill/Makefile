# $NetBSD: Makefile,v 1.26 2012/10/23 19:51:23 asau Exp $
#

DISTNAME=	skill-4.1.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.flux.utah.edu/pub/skill/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mysite.verizon.net/jforys/jeffware.html
COMMENT=	Signal processes given user names, ttys, commands, or pids

NOT_FOR_PLATFORM+= Interix-*-* # currently no machdep support

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
MAKE_ENV+=	OSTYPE=nbsd-44
.elif ${OPSYS} == "Darwin"
MAKE_ENV+=	OSTYPE=nbsd-44
.elif ${OPSYS} == "DragonFly"
MAKE_ENV+=	OSTYPE=nbsd-44
CPPFLAGS+=	-DHAS_STRERROR=1
.elif ${OPSYS} == "SunOS"
BINMODE=	02555
MAKE_ENV+=	OSTYPE=sys-5r4 BINGRP=sys CPPFLAGS=
.elif ${OPSYS} == "FreeBSD"
MAKE_ENV+=	OSTYPE=nbsd-44
.elif ${OPSYS} == "Linux"
MAKE_ENV+=	OSTYPE=linux-1
CPPFLAGS+=	-DHAS_STRERROR=1
.elif ${OPSYS} == "IRIX"
MAKE_ENV+=	OSTYPE=irix5
.elif ${OPSYS} == "OSF"
MAKE_ENV+=	OSTYPE=mach-3
.elif ${OPSYS} == "AIX"
MAKE_ENV+=	OSTYPE=aix-3
.elif ${OPSYS} == "HPUX"
MAKE_ENV+=	OSTYPE=hpux-10
.endif

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skill ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skill.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -f ${DESTDIR}${PREFIX}/bin/snice ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snice.1
	${LN} -s skill ${DESTDIR}${PREFIX}/bin/snice
	${LN} -s skill.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snice.1

.include "../../mk/bsd.pkg.mk"
