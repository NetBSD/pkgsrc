# $NetBSD: Makefile,v 1.11 2005/03/24 21:12:59 wiz Exp $

DISTNAME=	yale-tftpd-3.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	seb@NetBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

WRKSRC=		${WRKDIR}

SUBST_CLASSES+=			ytftpdman
SUBST_STAGE.ytftpdman=		post-configure
SUBST_MESSAGE.ytftpdman=	Fixing pathnames references
SUBST_FILES.ytftpdman=		tftpd.8
SUBST_SED.ytftpdman=		-e 's|@ETCDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.ytftpdman+=		-e 's|@PREFIX@|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
