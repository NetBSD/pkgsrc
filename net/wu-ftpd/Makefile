# $NetBSD: Makefile,v 1.6 1998/08/20 15:17:21 tsarna Exp $
# $FreeBSD Id: Makefile,v 1.16 1997/12/24 17:45:28 ache Exp
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

DISTNAME=       wu-ftpd-2.4.2-beta-16
PKGNAME=        wu-ftpd-2.4.2b16
CATEGORIES=	net
# AUSCERT recommendation
MASTER_SITES=   ftp://ftp.academ.com/pub/wu-ftpd/private/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     rh@vip.at
HOMEPAGE=	http://www.academ.com/academ/wu-ftpd/

do-build:
	cd ${WRKSRC} && ./build nbs PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
