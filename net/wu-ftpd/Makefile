# $NetBSD: Makefile,v 1.7 1999/02/13 09:05:02 rh Exp $
# $FreeBSD Id: Makefile,v 1.16 1997/12/24 17:45:28 ache Exp
#
# REMINDER: to use ftpaccess(5) you need to specify -a in command line,
# it is changed from previous versions

DISTNAME=       wu-ftpd-2.4.2-beta-18
PKGNAME=        wu-ftpd-2.4.2b18
CATEGORIES=	net
# AUSCERT recommendation
MASTER_SITES=   ftp://ftp.academ.com/pub/wu-ftpd/private/ \
		ftp://ftp.cp.in-berlin.de/pub/ftpsrc/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=     rh@netbsd.org
HOMEPAGE=	http://www.academ.com/academ/wu-ftpd/

CONFLICTS=	wu-ftpd*

MAKE_ENV+=	INSTALL="${INSTALL}"
MAKE_ENV+=	INSTALL_PROGRAM="${INSTALL_PROGRAM}"
MAKE_ENV+=	INSTALL_DATA="${INSTALL_DATA}"
MAKE_ENV+=	INSTALL_MAN="${INSTALL_MAN}"

do-build:
	cd ${WRKSRC} && ./build nbs PREFIX=${PREFIX}

.include "../../mk/bsd.pkg.mk"
