# $NetBSD: Makefile,v 1.1.1.1 1999/02/21 12:37:20 rh Exp $
#

DISTNAME=       wu-ftpd-2.4.2-beta-18-vr14
PKGNAME=        wu-ftpd-2.4.2b18.14
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.vr.net/pub/wu-ftpd/ \
		ftp://ftp.crc.ca/pub/packages/ftp/servers/wuarchive-ftpd-vr/ \
		ftp://ftp.ahol.com/pub/mirrors/wu-ftpd/ \
		ftp://ftp.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd-vr/ \
		ftp://ftp.gtn.com/pub/server/wuftpd/

MAINTAINER=     rh@netbsd.org
HOMEPAGE=	http://www.landfield.com/wu-ftpd/

MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

do-build:
	cd ${WRKSRC} && ./build nbs PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
