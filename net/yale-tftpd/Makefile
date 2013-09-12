# $NetBSD: Makefile,v 1.23 2013/09/12 11:15:12 jperkin Exp $

DISTNAME=	yale-tftpd-3.0
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

USE_BSD_MAKEFILE=	yes
USE_TOOLS=		nroff

WRKSRC=				${WRKDIR}

CFLAGS.DragonFly+=		-DHAVE_STRERROR
CFLAGS.FreeBSD+=		-DHAVE_STRERROR
CFLAGS.Linux+=			-DHAVE_STRERROR
CFLAGS.SunOS+=			-DHAVE_STRERROR -DBROKEN_TH_STUFF
LDFLAGS.SunOS+=			-lsocket -lnsl

USE_LANGUAGES=			c

SUBST_CLASSES+=			ytftpdman
SUBST_STAGE.ytftpdman=		post-configure
SUBST_MESSAGE.ytftpdman=	Fixing pathnames references
SUBST_FILES.ytftpdman=		tftpd.8
SUBST_SED.ytftpdman=		-e 's|@ETCDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.ytftpdman+=		-e 's|@PREFIX@|${PREFIX}|g'

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

# code is not clean enough for gcc-4.5
BUILDLINK_TRANSFORM+=		rm:-Werror

.include "../../mk/bsd.pkg.mk"
