# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 13:44:18 taca Exp $
# FreeBSD: ports/security/ruby-tcpwrap/Makefile,v 1.6 2000/09/26 08:02:10 knu Exp

DISTNAME=	ruby-tcpwrap-0.3
PKGNAME=	${RUBY_PKGNAMEPREFIX}tcpwrap-0.3
CATEGORIES=	security
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	# not available
COMMENT=	TCP wrappers library for Ruby

.include "../../mk/bsd.prefs.mk"

DEPENDS+=	libident>=0.22:../../security/libident
.if ${OPSYS} != "NetBSD"
DEPENDS+=	tcp_wrappers>=7.6:../../security/tcp_wrapper
.endif

DIST_SUBDIR=	ruby
USE_RUBY_EXTCONF= yes
WRKSRC=		${WRKDIR}/ruby-tcpwrap

.if ${OPSYS} == "NetBSD"
CONFIGURE_ARGS+= --with-libwrap-dir="/usr"
.else
CONFIGURE_ARGS+= --with-libwrap-dir="${LOCALBASE}"
.endif
INSTALL_TARGET=	site-install

DOCS_EN=	README.en doc/tcpwrap.html.en
DOCS_JA=	README.ja doc/tcpwrap.html.ja

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tcpwrap
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb ${RUBY_EXAMPLESDIR}/tcpwrap
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tcpwrap/ja
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tcpwrap
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_DOCDIR}/tcpwrap/ja
.endfor

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
