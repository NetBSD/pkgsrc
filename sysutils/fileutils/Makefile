# $NetBSD: Makefile,v 1.24 2002/12/06 16:12:55 grant Exp $

DISTNAME=		fileutils-4.1.11
CATEGORIES=		sysutils
MASTER_SITES=		ftp://alpha.gnu.org/pub/gnu/fileutils/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tron@netbsd.org
HOMEPAGE=		http://www.gnu.org/software/fileutils/fileutils.html
COMMENT=		GNU file management utilities

GNU_CONFIGURE=		# defined
USE_PKGLOCALEDIR=	# defined
USE_BUILDLINK2=		# defined
CONFIGURE_ARGS+=	--program-prefix=g \
			--with-libiconv-prefix=${BUILDLINK_PREFIX.libiconv}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == SunOS
CONFIGURE_SCRIPT=	${SH} ./configure
.endif

.include "../../converters/libiconv/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../mk/texinfo.mk"
.include "../../mk/bsd.pkg.mk"
