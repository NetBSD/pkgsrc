# $NetBSD: Makefile,v 1.4 2003/06/02 01:16:56 jschauma Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVD's on a DVD-Recorder

VERSION=	0.1.3

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

do-install:
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} dvdrecord ${PREFIX}/bin;	\
		${INSTALL_MAN} dvdrecord.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
