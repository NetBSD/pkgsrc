# $NetBSD: Makefile,v 1.7 2007/03/24 19:21:29 joerg Exp $
#

DISTNAME=	bftpd-1.0.24
CATEGORIES=	net
MASTER_SITES=	http://bftpd.sourceforge.net/downloads/src/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.bftpd.org/
COMMENT=	Small and fast FTP server

GNU_CONFIGURE=	YES

CFLAGS+=	-DPATH_BFTPD_CONF="\"${PKG_SYSCONFDIR}/bftpd.conf\""
CONF_FILES=	${PREFIX}/share/examples/bftpd/bftpd.conf \
		${PKG_SYSCONFDIR}/bftpd.conf
MAKE_ENV+=	VARBASE=${VARBASE:Q}

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man8

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bftpd

.include "../../mk/bsd.pkg.mk"
