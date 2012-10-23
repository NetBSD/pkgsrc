# $NetBSD: Makefile,v 1.19 2012/10/23 18:16:57 asau Exp $

DISTNAME=	ruby-tcpwrap-0.6
PKGNAME=	${RUBY_PKGPREFIX}-tcpwrap-0.6
PKGREVISION=	6
CATEGORIES=	security ruby
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	TCP wrappers library for Ruby
LICENSE=	2-clause-bsd

USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/ruby-tcpwrap
INSTALL_TARGET=		site-install
DOCS_EN=		README.en doc/tcpwrap.html.en
DOCS_JA=		README.ja doc/tcpwrap.html.ja

INSTALLATION_DIRS=	${RUBY_DOC}/tcpwrap/ja ${RUBY_EG}/tcpwrap

post-install:
	${INSTALL_DATA} ${WRKSRC}/sample/echod.rb \
		${DESTDIR}${PREFIX}/${RUBY_EG}/tcpwrap
.for f in ${DOCS_EN}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/tcpwrap
.endfor
.for f in ${DOCS_JA}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${PREFIX}/${RUBY_DOC}/tcpwrap/ja
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../security/libident/buildlink3.mk"
.include "../../security/tcp_wrappers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
