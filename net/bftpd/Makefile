# $NetBSD: Makefile,v 1.1.1.1 2003/06/02 13:13:15 jmmv Exp $
#

DISTNAME=	bftpd-1.0.24
CATEGORIES=	net
MASTER_SITES=	http://bftpd.sourceforge.net/downloads/src/

MAINTAINER=	virtus@wanadoo.nl
HOMEPAGE=	http://www.bftpd.org/
COMMENT=	Small and fast FTP server

USE_BUILDLINK2=	YES
USE_PKGINSTALL=	YES
GNU_CONFIGURE=	YES

CFLAGS+=	-DPATH_BFTPD_CONF=\"\\\"${PKG_SYSCONFDIR}/bftpd.conf\\\"\"
CONF_FILES=	${PREFIX}/share/examples/bftpd/bftpd.conf \
		${PKG_SYSCONFDIR}/bftpd.conf

pre-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/examples/bftpd

.include "../../mk/bsd.pkg.mk"
