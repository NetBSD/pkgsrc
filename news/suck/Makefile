# $NetBSD: Makefile,v 1.9 2001/01/21 18:25:04 veego Exp $
#

DISTNAME=	ruby-1.4.3
CATEGORIES=	lang
MASTER_SITES=	ftp://ftp.TokyoNet.AD.JP/pub/misc/ruby/ \
		ftp://ftp.iij.ad.jp/pub/lang/ruby/ \
		ftp://ftp.netlab.co.jp/pub/lang/ruby/ \
		ftp://blade.nagaokaut.ac.jp/pub/lang/ruby/ \
		ftp://ftp.krnet.ne.jp/pub/ruby/ \
		ftp://ftp.mirror.nucba.ac.jp/mirror/ruby/ \
		http://mirror.nucba.ac.jp/mirror/ruby/

MAINTAINER=	sakamoto@netbsd.org
HOMEPAGE=	http://www.ruby-lang.org/

BUILD_DEPENDS=	${LOCALBASE}/bin/bison:../../devel/bison
DEPENDS+=	gdbm-1.7.3:../../databases/gdbm
DEPENDS+=	ncurses>=4.2:../../devel/ncurses
DEPENDS+=	readline-4.0:../../devel/readline

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+= --enable-shared
MAKE_ENV+=	DLDFLAGS="-L${LOCALBASE}/lib -R${LOCALBASE}/lib -L${X11BASE}/lib -R${X11BASE}/lib"

PLIST_SUBST=	RUBY_VERSION=1.4

post-patch:
	${RM} -f ${WRKSRC}/ext/tcltklib/MANIFEST
	${RM} -f ${WRKSRC}/ext/tk/MANIFEST

post-install:
	strip ${PREFIX}/bin/ruby
	${MKDIR} ${PR

.include "../../mk/bsd.pkg.mk"
