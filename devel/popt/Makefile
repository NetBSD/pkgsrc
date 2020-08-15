# $NetBSD: Makefile,v 1.49 2020/08/15 01:02:42 tnn Exp $
#

DISTNAME=	popt-1.18
CATEGORIES=	devel
MASTER_SITES=	http://ftp.rpm.org/popt/releases/popt-1.x/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/rpm-software-management/popt
COMMENT=	Command line option parsing library
# mit license with advertising clause
LICENSE=	mit

CONFLICTS=		ORBit<=0.5.3

USE_PKGLOCALEDIR=		yes
GNU_CONFIGURE=			yes
USE_TOOLS+=			gmake
USE_LIBTOOL=			yes
PKGCONFIG_OVERRIDE=		popt.pc
PKGCONFIG_OVERRIDE_STAGE=	post-configure

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
