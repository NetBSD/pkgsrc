# $NetBSD: Makefile,v 1.8 2004/02/08 13:18:13 grant Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVDs on a DVD-Recorder

VERSION=	0.1.5

USE_BUILDLINK2=		# defined
GNU_CONFIGURE=		# defined

LIBS.SunOS+=		-lsocket

do-install:
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} dvdrecord ${PREFIX}/bin;		\
		${INSTALL_MAN} dvdrecord.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
