# $NetBSD: Makefile,v 1.4 1999/12/27 12:50:59 rh Exp $
#

DISTNAME=       wu-ftpd-2.4.2-vr16
PKGNAME=        wu-ftpd-vr-2.4.2.16
CATEGORIES=	net
MASTER_SITES=   ftp://ftp.vr.net/pub/wu-ftpd/ \
		ftp://ftp.crc.ca/pub/packages/ftp/servers/wuarchive-ftpd-vr/ \
		ftp://ftp.ahol.com/pub/mirrors/wu-ftpd/ \
		ftp://ftp0.sunet.se/pub/nir/ftp/servers/wuarchive-ftpd-vr/ \
		ftp://ftp.gtn.com/pub/server/wuftpd/

MAINTAINER=     rh@netbsd.org
HOMEPAGE=	http://www.landfield.com/wu-ftpd/

BROKEN=		"superceded by wu-ftpd package"

CONFLICTS+=	wu-ftpd-* beroftpd-*

MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

do-build:
	cd ${WRKSRC} && ./build nbs PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
