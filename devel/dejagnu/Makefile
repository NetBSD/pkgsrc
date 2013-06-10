# $NetBSD: Makefile,v 1.16 2013/06/10 01:09:48 mef Exp $
#

DISTNAME=	dejagnu-1.5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNU:=dejagnu/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnu.org/software/dejagnu/dejagnu.html
COMMENT=	TCL/Expect-based framework for regression testing
LICENSE=	gnu-gpl-v3

DEPENDS+=	tcl-expect>=5.32.1:../../lang/tcl-expect

GNU_CONFIGURE=	yes
INFO_FILES=	yes

CONFIGURE_ARGS+=	--infodir=${PREFIX}/info

INSTALL_TARGET=	install install-info

# c++ is necessary for make test
USE_LANGUAGES+=	c c++
TEST_TARGET=	check
TEST_ENV=	PATH=/usr/bin:/bin:${PREFIX}/bin

.include "../../mk/bsd.pkg.mk"
