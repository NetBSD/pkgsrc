# $NetBSD: Makefile,v 1.20 2002/09/10 16:06:48 wiz Exp $

DISTNAME=		fileutils-4.1.8
PKGREVISION=		1
CATEGORIES=		sysutils
MASTER_SITES=		ftp://alpha.gnu.org/pub/gnu/fileutils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=		GNU file management utilities

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--program-prefix=g \
			--with-libiconv-prefix=${BUILDLINK_DIR}
MAKE_ENV+=		PKGLOCALEDIR="${PKGLOCALEDIR}"

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/gettext-lib/buildlink.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
