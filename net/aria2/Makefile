# $NetBSD: Makefile,v 1.28 2011/08/09 17:00:57 ryoon Exp $
#

DISTNAME=	aria2-1.12.1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=aria2/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://aria2.sourceforge.net/
COMMENT=	Multi-threaded, multi-protocol, flexible download accelerator
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+=	--enable-bittorrent
CONFIGURE_ARGS+=	--enable-metalink
CONFIGURE_ARGS+=	--with-included-gettext=no
CONFIGURE_ARGS+=	--with-libexpat
CONFIGURE_ARGS+=	--without-libxml2

GCC_REQD+=		3.4
TEST_TARGET=		check
USE_FEATURES=		getopt_long snprintf

.include "../../mk/compiler.mk"

.if !empty(PKGSRC_RUN_TEST:M[Yy][Ee][Ss])
BUILDLINK_DEPMETHOD.cppunit=	build
BUILDLINK_API_DEPENDS.cppunit+=	cppunit>=1.10.2
.  include "../../devel/cppunit/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xmltest
.endif

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../net/libcares/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
