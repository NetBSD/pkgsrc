# $NetBSD: Makefile,v 1.9 2005/01/28 14:08:01 taca Exp $
# FreeBSD: ports/security/ruby-tcpwrap/Makefile,v 1.6 2000/09/26 08:02:10 knu Exp

DISTNAME=	ruby-tcpwrap-0.6
PKGNAME=	${RUBY_PKGPREFIX}-tcpwrap-0.6
PKGREVISION=	1
CATEGORIES=	security ruby
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	TCP wrappers library for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_BUILDLINK3=		yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/ruby-tcpwrap
INSTALL_TARGET=		site-install
DOCS_EN=		README.en doc/tcpwrap.html.en
DOCS_JA=		README.ja doc/tcpwrap.html.ja

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

.include "../../lang/ruby/modules.mk"
.include "../../security/libident/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
