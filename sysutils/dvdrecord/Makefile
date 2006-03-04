# $NetBSD: Makefile,v 1.14 2006/03/04 21:30:40 jlam Exp $

DISTNAME=	dvdrtools-${VERSION}
PKGNAME=	${DISTNAME:S/dvdrtools/dvdrecord/}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://freesoftware.fsf.org/download/dvdrtools/dvdrtools.pkg/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/dvdrtools/
COMMENT=	This program allows you to create DVDs on a DVD-Recorder

VERSION=	0.1.5

GNU_CONFIGURE=		yes
LIBS.SunOS+=		-lsocket
INSTALLATION_DIRS=	bin man/man1

do-install:
	cd ${WRKSRC}/cdrecord;						\
		${INSTALL_PROGRAM} dvdrecord ${PREFIX}/bin;		\
		${INSTALL_MAN} dvdrecord.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
