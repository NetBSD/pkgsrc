# $NetBSD: Makefile,v 1.4 2013/12/06 21:50:12 joerg Exp $

DISTNAME=		CUnit-2.1-0-src
PKGNAME=		CUnit-2.1
PKGREVISION=		1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cunit/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cunit.sourceforge.net/
COMMENT=		C Unit checking test software

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
DEPENDS+=		autoconf-[0-9]*:../../devel/autoconf

WRKSRC=			${WRKDIR}/CUnit-2.1-0

INSTALLATION_DIRS+=	include/CUnit share/doc/CUnit
INSTALLATION_DIRS+=	share/CUnit share/doc/CUnit/headers

.include "../../mk/bsd.pkg.mk"
