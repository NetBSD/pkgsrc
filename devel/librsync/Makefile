# $NetBSD: Makefile,v 1.9 2004/10/03 00:13:30 tv Exp $
#

DISTNAME=		librsync-0.9.6
PKGREVISION=		3
CATEGORIES=		devel net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librsync/}

MAINTAINER=		davids@idiom.com
HOMEPAGE=		http://rdiff-backup.stanford.edu/
COMMENT=		Checksum-based differencing library

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-popt
USE_LIBTOOL=		yes
USE_BUILDLINK3=		yes

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
