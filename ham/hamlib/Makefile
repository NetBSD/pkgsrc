# $NetBSD: Makefile,v 1.39 2016/07/09 06:38:23 wiz Exp $
#

DISTNAME=	hamlib-3.0.1
PKGREVISION=	1
CATEGORIES=	ham
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hamlib/}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://hamlib.sourceforge.net/
COMMENT=	API for digital communications equipment
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
GNU_CONFIGURE=	yes
INFO_FILES=     yes
USE_LIBTOOL=	yes

# \todo Consider language bindings.
CONFIGURE_ARGS+=--without-tcl-binding \
		--without-perl-binding \
		--without-python-binding

.include "../../mk/bsd.prefs.mk"

TEST_TARGET=	check

# \todo Consider adding readline.

.include "../../devel/libltdl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
