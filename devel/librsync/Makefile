# $NetBSD: Makefile,v 1.3 2003/07/21 16:43:31 martti Exp $
#

DISTNAME=		librsync-0.9.5.1
PKGREVISION=		1
CATEGORIES=		devel net
MASTER_SITES=		http://rdiff-backup.stanford.edu/

MAINTAINER=		davids@idiom.com
HOMEPAGE=		http://rdiff-backup.stanford.edu/
COMMENT=		Checksum-based differencing library

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--without-included-popt
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
USE_BUILDLINK2=		yes

.include "../../archivers/bzip2/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/popt/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"

.include "../../mk/bsd.pkg.mk"
