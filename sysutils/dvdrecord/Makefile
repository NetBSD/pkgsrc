# $NetBSD: Makefile,v 1.1.1.1 2003/01/17 13:53:11 toshii Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVD's on a DVD-Recorder

VERSION=	0.1.3

CONFLICTS=	mkisofs-[0-9]*

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

do-install:
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} dvdrecord ${PREFIX}/bin;	\
		${INSTALL_MAN} dvdrecord.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
