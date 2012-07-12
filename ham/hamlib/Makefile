# $NetBSD: Makefile,v 1.28.2.1 2012/07/12 00:38:18 gdt Exp $
#

DISTNAME=	hamlib-1.2.15.1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge.net/
COMMENT=	API for digital communications equipment

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

CONFIGURE_ARGS+=--without-tcl-binding \
		--without-perl-binding \
		--without-python-binding

# The configure script is broken. It even requires a Python interpreter
# when none is needed.
CONFIGURE_ENV+=	PYTHON=/nonexistent

TEST_TARGET=	check

INSTALLATION_DIRS=	include/hamlib

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
