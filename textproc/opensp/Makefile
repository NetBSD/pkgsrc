# $NetBSD: Makefile,v 1.38 2011/04/22 13:41:59 obache Exp $
#

DISTNAME=	OpenSP-1.5.2
PKGNAME=	${DISTNAME:S/OpenSP/opensp/}
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openjade/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://openjade.sourceforge.net/doc/index.htm
COMMENT=	SGML parser, successor to "sp"

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	xmlto-[0-9]*:../../textproc/xmlto

CONFLICTS+=	sp-[0-9]*

USE_TOOLS+=		gmake msgfmt perl
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
PTHREAD_OPTS+=		require
USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-http \
			--enable-default-catalog=${PREFIX}/share/sgml/catalog
REPLACE_PERL+=		unicode/gensyntax.pl

TEST_TARGET=		check

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
