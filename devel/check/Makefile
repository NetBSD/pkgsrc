# $NetBSD: Makefile,v 1.19 2013/10/03 14:48:07 taca Exp $
#

DISTNAME=	check-0.9.10
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
