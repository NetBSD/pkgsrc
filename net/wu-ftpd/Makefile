# New ports collection makefile for:	wu-ftpd
# Version required:     2.4.2-beta-16
# Date created:		18 Oct 1994
# Whom:			torstenb
#
# $NetBSD: Makefile,v 1.3 1998/03/30 18:40:25 tron Exp $
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

MAN1=		ftpcount.1 ftpwho.1
MAN5=		ftpaccess.5 ftphosts.5 ftpconversions.5 xferlog.5
MAN8=		ftpd.8 ftpshut.8

do-build:
	cd ${WRKSRC} && ./build nbs PREFIX=${PREFIX}

.include <bsd.port.mk>
