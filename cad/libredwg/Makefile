# $NetBSD: Makefile,v 1.9 2022/06/28 11:31:01 wiz Exp $
#

DISTNAME=		libredwg-0.12.4
PKGREVISION=		2
CATEGORIES=		cad
MASTER_SITES=		https://ftp.gnu.org/gnu/libredwg/
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnu.org/software/libredwg
COMMENT=		Free library to read/write DWG files
LICENSE=		gnu-gpl-v3

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_TOOLS+=		makeinfo perl:test

CONFIGURE_ARGS+=	--infodir=${PREFIX}/${PKGINFODIR}
CONFIGURE_ARGS+=	--disable-bindings

INFO_FILES=		yes

TEST_TARGET=		check

.include "../../devel/pcre2/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"		# test target
.include "../../textproc/py-libxml2/buildlink3.mk"	# test target
.include "../../print/pslib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
