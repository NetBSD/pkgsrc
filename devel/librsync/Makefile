# $NetBSD: Makefile,v 1.6 2003/11/12 01:31:48 salo Exp $
#

DISTNAME=		librsync-0.9.6
PKGREVISION=		2
CATEGORIES=		devel net
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=librsync/}

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
