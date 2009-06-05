# $NetBSD: Makefile,v 1.18 2009/06/05 10:19:10 hasso Exp $

DISTNAME=	yale-tftpd-3.0
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_BSD_MAKEFILE=	yes

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

.include "../../mk/bsd.pkg.mk"
