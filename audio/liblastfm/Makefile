# $NetBSD: Makefile,v 1.2 2010/04/09 23:49:14 markd Exp $
#

DISTNAME=	liblastfm-0.3.0
PKGREVISION=	2
CATEGORIES=	audio net
MASTER_SITES=	http://cdn.last.fm/src/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://github.com/mxcl/liblastfm/tree/master
COMMENT=	Library for accessing last.fm
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	ruby-[0-9]*:../../lang/ruby

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bash gmake perl pkg-config
PREPEND_PATH+=		${QTDIR}/bin

HAS_CONFIGURE=		yes
CONFIGURE_ARGS+=	--prefix ${PREFIX}
#CONFIGURE_ARGS+=	--release
#CPPFLAGS+=		-fPIC
CONFIG_SHELL=		ruby

REPLACE_PERL=		admin/findsrc
REPLACE_INTERPRETER+=	ruby
REPLACE.ruby.old=	.*ruby
REPLACE.ruby.new=	${LOCALBASE}/bin/ruby
REPLACE_FILES.ruby+=	admin/which_qmake.rb
REPLACE_FILES.ruby+=	admin/lastfm.h.rb
REPLACE_FILES.ruby+=	admin/Makefile.rb
REPLACE_FILES.ruby+=	admin/platform.rb
REPLACE_FILES.ruby+=	admin/utils.rb

pre-configure:
	${LN} -sf ${QTDIR}/bin/qmake ${BUILDLINK_DIR}/bin/

.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../math/fftwf/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
