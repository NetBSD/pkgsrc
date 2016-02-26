# $NetBSD: Makefile,v 1.28 2016/02/26 10:24:13 jperkin Exp $
#

DISTNAME=	skill-4.1.4
CATEGORIES=	sysutils
MASTER_SITES=	ftp://ftp.flux.utah.edu/pub/skill/
EXTRACT_SUFX=	.tgz

MAINTAINER=	kim@tac.nyc.ny.us
HOMEPAGE=	http://mysite.verizon.net/jforys/jeffware.html
COMMENT=	Signal processes given user names, ttys, commands, or pids

BROKEN_ON_PLATFORM+= Interix-*-* # currently no machdep support

MAKE_ENV.AIX+=		OSTYPE=aix-3
MAKE_ENV.Darwin+=	OSTYPE=nbsd-44
MAKE_ENV.DragonFly+=	OSTYPE=nbsd-44
MAKE_ENV.FreeBSD+=	OSTYPE=nbsd-44
MAKE_ENV.HPUX+=		OSTYPE=hpux-10
MAKE_ENV.IRIX+=		OSTYPE=irix5
MAKE_ENV.Linux+=	OSTYPE=linux-1
MAKE_ENV.NetBSD+=	OSTYPE=nbsd-44
MAKE_ENV.OSF+=		OSTYPE=mach-3
MAKE_ENV.SunOS+=	OSTYPE=sys-5r4 BINGRP=sys CPPFLAGS=

CPPFLAGS.DragonFly+=	-DHAS_STRERROR=1
CPPFLAGS.Linux+=	-DHAS_STRERROR=1

OPSYSVARS+=		BINMODE
BINMODE.SunOS=		02555

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

pre-install:
	${INSTALL_PROGRAM} ${WRKSRC}/skill ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/skill.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${RM} -f ${DESTDIR}${PREFIX}/bin/snice ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snice.1
	${LN} -s skill ${DESTDIR}${PREFIX}/bin/snice
	${LN} -s skill.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/snice.1

.include "../../mk/bsd.pkg.mk"
