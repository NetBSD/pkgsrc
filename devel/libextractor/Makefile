# $NetBSD: Makefile,v 1.3 2004/11/29 02:25:26 tv Exp $
#

DISTNAME=		libextractor-0.3.11
CATEGORIES=		devel
MASTER_SITES=		http://ovmj.org/libextractor/download/

MAINTAINER=		tv@duh.org
HOMEPAGE=		http://ovmj.org/libextractor/
COMMENT=		Metadata extractor for various file data types

USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
PTHREAD_OPTS+=		require

CONFLICTS=		csound-{bath,dev}-*	# bin/extract

# This package requires dlopen, so save on space by skipping non-PIC libs
SHLIBTOOL_OVERRIDE=	${WRKSRC}/libtool

.include "../../devel/libltdl/convenience.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
