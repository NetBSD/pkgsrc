# $NetBSD: Makefile,v 1.6 2016/12/29 23:12:23 wiz Exp $

DISTNAME=	xen-${VERSION}
PKGNAME=	xenstoretools-${VERSION}
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://bits.xensource.com/oss-xen/release/${VERSION}/

DISTFILES=	${DISTNAME}.tar.gz
DISTFILES+=	ipxe-git-v${VERSION_IPXE}.tar.gz
SITES.ipxe-git-v${VERSION_IPXE}.tar.gz+= http://xenbits.xensource.com/xen-extfiles/

MAINTAINER=		sborrill@NetBSD.org
HOMEPAGE=		http://xen.org/
COMMENT=		Xenstore Tools for Xen 4.1.x
LICENSE=		gnu-gpl-v2

VERSION=		4.1.6.1
VERSION_IPXE=		1.0.0

BUILD_DIRS=		xenstore
BUILD_TARGET=		clients
INSTALL_TARGET=		installclients
INSTALL_DIRS=		xenstore

PKG_SYSCONFSUBDIR=	xen
WRKSRC=			${WRKDIR}/xen-${VERSION}/tools
BUILD_DEFS+=		VARBASE

ONLY_FOR_PLATFORM=	Linux-2.6*-i386 Linux-2.6*-x86_64
ONLY_FOR_PLATFORM+=	NetBSD-[5-9].*-x86_64 NetBSD-[5-9].*-i386

CONFLICTS+=		libxen-[0-9]*
CONFLICTS+=		xentools20-[0-9]*
CONFLICTS+=		xentools3*
CONFLICTS+=		xentools4*

USE_TOOLS+=		gmake

MAKE_ENV+=		PREFIX=${prefix:Q} WRKSRC=${WRKSRC}
MAKE_ENV+=		MV=${MV:Q} PYTHON=${PYTHONBIN:Q} SED=${SED:Q}
MAKE_ENV+=		VARBASE=${VARBASE}

RCD_SCRIPTS=		xendomname
FILES_SUBST+=		PREFIX=${PREFIX}

.include "../../mk/bsd.prefs.mk"

INSTALLATION_DIRS=	bin lib

pre-build:
	${LN} -s ../../xen/include/public ${WRKSRC}/xenstore/xen

.include "../../mk/bsd.pkg.mk"
