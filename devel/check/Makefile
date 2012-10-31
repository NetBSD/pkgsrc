# $NetBSD: Makefile,v 1.17 2012/10/31 11:16:45 asau Exp $
#

DISTNAME=	check-0.9.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=check/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://check.sourceforge.net/
COMMENT=	Unit test framework for C
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
INFO_FILES=	yes

PKGCONFIG_OVERRIDE=	check.pc.in

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
