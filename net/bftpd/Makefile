# $NetBSD: Makefile,v 1.10.20.1 2010/06/07 19:06:20 tron Exp $
#

DISTNAME=	bftpd-2.9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=bftpd/}

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://bftpd.sourceforge.net/
COMMENT=	Small and fast FTP server
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
WRKSRC=		${WRKDIR}/bftpd

CONF_FILES=	${PREFIX}/share/examples/bftpd/bftpd.conf \
		${PKG_SYSCONFDIR}/bftpd.conf

SUBST_CLASSES+=		varbase
SUBST_STAGE.varbase=	post-configure
SUBST_FILES.varbase=	bftpd.conf
SUBST_SED.varbase=	-e 's|/var/|${VARBASE}/|g'

SUBST_CLASSES+=		sysconf
SUBST_STAGE.sysconf=	post-configure
SUBST_FILES.sysconf=	mypaths.h bftpd.8
SUBST_SED.sysconf=	-e 's|/etc/|${PKG_SYSCONFDIR}/|g'

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/bftpd

BUILD_DEFS+=		VARBASE

.include "../../mk/bsd.pkg.mk"
