# $NetBSD: Makefile,v 1.54 2024/09/12 22:31:17 gutteridge Exp $
#

DISTNAME=	OpenSP-1.5.2
PKGNAME=	${DISTNAME:S/OpenSP/opensp/}
PKGREVISION=	11
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjade.sourceforge.net/doc/index.htm
COMMENT=	SGML parser, successor to "sp"

TOOL_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFLICTS+=	sp-[0-9]*

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++03
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog
REPLACE_PERL+=		unicode/gensyntax.pl

# Avoid bogus error with GCC 14 on some Linux distros.
CFLAGS.Linux+=		-fpermissive

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
