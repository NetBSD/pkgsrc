# $NetBSD: Makefile,v 1.10 2004/11/25 14:25:22 adam Exp $

DISTNAME=	librsync-0.9.7
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=librsync/}

MAINTAINER=	davids@idiom.com
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	Checksum-based differencing library

USE_BUILDLINK3=		yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-popt

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
