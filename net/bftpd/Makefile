# $NetBSD: Makefile,v 1.10 2008/07/10 15:52:03 joerg Exp $
#

DISTNAME=	bftpd-1.0.24
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://bftpd.sourceforge.net/downloads/src/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://bftpd.sourceforge.net/
COMMENT=	Small and fast FTP server

GNU_CONFIGURE=	YES

CFLAGS+=	-DPATH_BFTPD_CONF="\"${PKG_SYSCONFDIR}/bftpd.conf\""
CONF_FILES=	${PREFIX}/share/examples/bftpd/bftpd.conf \
		${PKG_SYSCONFDIR}/bftpd.conf
MAKE_ENV+=	VARBASE=${VARBASE:Q}

INSTALLATION_DIRS=	sbin ${PKGMANDIR}/man8 share/examples/bftpd

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.pkg.mk"
