# $NetBSD: Makefile,v 1.33 2002/03/25 12:30:09 grant Exp $
#

DISTNAME=	slang-1.4.5
PKGNAME=	lib${DISTNAME}
SVR4_PKGNAME=	lslan
CATEGORIES=	devel
MASTER_SITES=	ftp://space.mit.edu/pub/davis/slang/v1.4/ \
		http://gd.tuwien.ac.at/editors/davis/slang/v1.4/ \
		ftp://ftp.uni-stuttgart.de/pub/unix/misc/slang/v1.4/ \
		ftp://ftp.fu-berlin.de/pub/unix/news/slrn/v1.4/ \
		ftp://ftp.ntua.gr/pub/lang/slang/v1.4/ \
		ftp://ftp.plig.org/pub/slang/v1.4/ \
		ftp://ftp.gigabell.net/pub/lang/1.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=    	packages@netbsd.org
HOMEPAGE=	http://www.s-lang.org/
COMMENT=	Routines for rapid alpha-numeric terminal applications development

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE= 	yes
USE_LIBTOOL=	yes
USE_GMAKE=	yes

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/slang
	${MV} ${PREFIX}/share/doc/slang/slangdoc.html \
		${PREFIX}/share/doc/html/slang

.include "../../mk/bsd.pkg.mk"
