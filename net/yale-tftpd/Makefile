# $NetBSD: Makefile,v 1.10 2004/03/21 10:29:51 seb Exp $
# FreeBSD Id: ports/ftp/yale-tftpd/Makefile,v 1.14 2000/04/12 05:31:29 mharo Exp

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
