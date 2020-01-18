# $NetBSD: Makefile,v 1.6 2020/01/18 23:30:25 rillig Exp $

DISTNAME=		CUnit-2.1-0-src
PKGNAME=		CUnit-2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cunit/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://cunit.sourceforge.net/
COMMENT=		C Unit checking test software

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf

WRKSRC=			${WRKDIR}/CUnit-2.1-0

INSTALLATION_DIRS+=	include/CUnit share/doc/CUnit
INSTALLATION_DIRS+=	share/CUnit share/doc/CUnit/headers

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
