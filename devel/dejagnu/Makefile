# $NetBSD: Makefile,v 1.23 2020/01/18 23:30:26 rillig Exp $
#

DISTNAME=	dejagnu-1.6.2
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=dejagnu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnu.org/software/dejagnu/dejagnu.html
COMMENT=	TCL/Expect-based framework for regression testing
LICENSE=	gnu-gpl-v3

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

GNU_CONFIGURE=	yes
INFO_FILES=	yes
USE_TOOLS=	gmake

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

INSTALL_TARGET=	install install-info

# c++ is necessary for make test
USE_LANGUAGES+=	c c++
TEST_TARGET=	check
TEST_ENV=	PATH=/usr/bin:/bin:${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
