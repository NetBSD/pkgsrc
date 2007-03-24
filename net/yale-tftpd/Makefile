# $NetBSD: Makefile,v 1.15 2007/03/24 19:21:31 joerg Exp $

DISTNAME=	yale-tftpd-3.0
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

WRKSRC=		${WRKDIR}

SUBST_CLASSES+=			ytftpdman
SUBST_STAGE.ytftpdman=		post-configure
SUBST_MESSAGE.ytftpdman=	Fixing pathnames references
SUBST_FILES.ytftpdman=		tftpd.8
SUBST_SED.ytftpdman=		-e 's|@ETCDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.ytftpdman+=		-e 's|@PREFIX@|${PREFIX}|g'

INSTALLATION_DIRS=	libexec ${PKGMANDIR}/cat8 ${PKGMANDIR}/man8

.include "../../mk/bsd.pkg.mk"
