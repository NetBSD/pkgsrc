# $NetBSD: Makefile,v 1.8 2000/01/15 18:46:29 jlam Exp $
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
	${MKDIR} ${PREFIX}/share/examples/ruby
	${INSTALL_DATA} ${WRKSRC}/sample/* ${PREFIX}/share/examples/ruby
	${MKDIR} ${PREFIX}/share/examples/ruby/misc
	${INSTALL_DATA} ${WRKSRC}/misc/* ${PREFIX}/share/examples/ruby/misc

.include "../../mk/bsd.pkg.mk"
