# $NetBSD: Makefile,v 1.16 2009/02/15 03:27:56 taca Exp $

DISTNAME=	ruby-tcpwrap-0.6
PKGNAME=	${RUBY_PKGPREFIX}-tcpwrap-0.6
PKGREVISION=	5
CATEGORIES=	security ruby
MASTER_SITES=	http://www.shugo.net/archive/ruby-tcpwrap/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	# not available
COMMENT=	TCP wrappers library for Ruby

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_EXTCONF=	yes
WRKSRC=			${WRKDIR}/ruby-tcpwrap
INSTALL_TARGET=		site-install
DOCS_EN=		README.en doc/tcpwrap.html.en
DOCS_JA=		README.ja doc/tcpwrap.html.ja

INSTALLATION_DIRS=	${RUBY_DOC}/tcpwrap/ja ${RUBY_EG}/tcpwrap
PKG_DESTDIR_SUPPORT=	destdir

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
