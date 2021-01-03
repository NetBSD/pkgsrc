# $NetBSD: Makefile,v 1.8 2021/01/03 11:23:16 wiz Exp $

DISTNAME=		CUnit-2.1-0-src
PKGNAME=		CUnit-2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cunit/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cunit.sourceforge.net/
COMMENT=		C Unit checking test software

USE_TOOLS+=		autoconf:run
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes

WRKSRC=			${WRKDIR}/CUnit-2.1-0

INSTALLATION_DIRS+=	include/CUnit share/doc/CUnit
INSTALLATION_DIRS+=	share/CUnit share/doc/CUnit/headers

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
