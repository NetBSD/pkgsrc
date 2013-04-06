# $NetBSD: Makefile,v 1.17 2013/04/06 03:45:09 rodent Exp $

DISTNAME=	cvsup-gui-static-16.1.h
PKGNAME=	${DISTNAME:C/static/bin/}
PKGREVISION=	1
CATEGORIES=	devel scm
MASTER_SITES=	http://motoyuki.bsdclub.org/data/NetBSD/CVSup/i386/
EXTRACT_SUFX=	.tgz

MAINTAINER=	motoyuki@bsdclub.org
HOMEPAGE=	http://www.cvsup.org/
COMMENT=	GUI client for cvsup

CVSUP_VERSION=	${DISTNAME:S/cvsup-gui-static-//}

DEPENDS+=	cvsup-bin>=${CVSUP_VERSION}:../../devel/cvsup-bin

EMUL_PLATFORMS=		netbsd-i386
EMUL_REQD=		netbsd>=1.5

# XXX Remove the following line on next update; see PR 25255 for details
DIST_SUBDIR=		cvsup-i386-1.6

WRKSRC=			${WRKDIR}
NO_CONFIGURE=		yes
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/cvsup ${DESTDIR}${PREFIX}/bin/cvsup-gui

.include "../../mk/bsd.pkg.mk"
