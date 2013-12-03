# $NetBSD: Makefile,v 1.1 2013/12/03 01:27:43 mef Exp $

DISTNAME=	confuse-2.7
PKGNAME=	${DISTNAME:C/^/lib/}

CATEGORIES=	devel
MASTER_SITES=	http://savannah.nongnu.org/download/confuse/
LICENSE=	isc

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/confuse/
COMMENT=	Configuration file parser library

# Following args mentioned in DESCR (and configure) but no effect for the moment
CONFIGURE_ARGS+= --enable-shared

USE_LIBTOOL=	yes

GNU_CONFIGURE=		yes

.include "../../mk/bsd.pkg.mk"
