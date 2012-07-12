# $NetBSD: Makefile,v 1.28.2.2 2012/07/12 00:38:45 gdt Exp $
#

DISTNAME=	hamlib-1.2.15.1
#PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	pkgsrc-users@NetBSD.org
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

INSTALLATION_DIRS=	include/hamlib

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
