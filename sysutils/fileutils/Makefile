# $NetBSD: Makefile,v 1.22 2002/10/09 17:26:18 wiz Exp $

DISTNAME=		fileutils-4.1.8
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://alpha.gnu.org/pub/gnu/fileutils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=		GNU file management utilities

GNU_CONFIGURE=		YES
USE_BUILDLINK2=		YES
CONFIGURE_ARGS+=	--program-prefix=g \
			--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
