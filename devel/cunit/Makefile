# $NetBSD: Makefile,v 1.2 2009/07/31 21:23:14 agc Exp $

DISTNAME=		CUnit-2.1-0-src
PKGNAME=		CUnit-2.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=cunit/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://cunit.sourceforge.net/
COMMENT=		C Unit checking test software

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
DEPENDS+=		autoconf-*:../../devel/autoconf

WRKSRC=			${WRKDIR}/CUnit-2.1-0

INSTALLATION_DIRS+=	include/CUnit share/doc/CUnit
INSTALLATION_DIRS+=	share/CUnit share/doc/CUnit/headers

.include "../../mk/bsd.pkg.mk"
