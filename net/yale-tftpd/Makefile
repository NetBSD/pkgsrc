# $NetBSD: Makefile,v 1.12 2005/12/27 13:54:59 seb Exp $

DISTNAME=	yale-tftpd-3.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	ftp://ftp.cert.dfn.de/pub/tools/net/yale-tftpd/

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Enhanced tftpd(8) from Yale University and cisco Systems

WRKSRC=		${WRKDIR}

SUBST_CLASSES+=			ytftpdman
SUBST_STAGE.ytftpdman=		post-configure
SUBST_MESSAGE.ytftpdman=	Fixing pathnames references
SUBST_FILES.ytftpdman=		tftpd.8
SUBST_SED.ytftpdman=		-e 's|@ETCDIR@|${PKG_SYSCONFDIR}|g'
SUBST_SED.ytftpdman+=		-e 's|@PREFIX@|${PREFIX}|g'

.include "../../mk/bsd.pkg.mk"
