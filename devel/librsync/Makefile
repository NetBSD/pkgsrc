# $NetBSD: Makefile,v 1.12 2005/07/14 13:52:13 wiz Exp $

DISTNAME=	librsync-0.9.7
CATEGORIES=	devel net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=librsync/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://rdiff-backup.stanford.edu/
COMMENT=	Checksum-based differencing library

USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-included-popt

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
