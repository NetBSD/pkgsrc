# $NetBSD: Makefile,v 1.9 2005/03/24 21:12:56 wiz Exp $

DISTNAME=	tmail-0.10.8
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.loveruby.net/archive/tmail/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/tmail.html
COMMENT=	Mail manipulating library for Ruby including MIME multipart support

RUBY_HAS_ARCHLIB=	yes
USE_RUBY_SETUP=		yes

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tmail/en
	${INSTALL_DATA} ${WRKSRC}/BUGS ${WRKSRC}/ChangeLog ${WRKSRC}/TODO \
		${RUBY_DOCDIR}/tmail
	${INSTALL_DATA} ${WRKSRC}/Incompatibilities ${WRKSRC}/README.en \
		${RUBY_DOCDIR}/tmail/en
	${INSTALL_DATA} ${WRKSRC}/doc.en/*.html ${RUBY_DOCDIR}/tmail/en
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tmail/ja
	${INSTALL_DATA} ${WRKSRC}/Incompatibilities.ja ${WRKSRC}/README.ja \
		${RUBY_DOCDIR}/tmail/ja
	${INSTALL_DATA} ${WRKSRC}/doc.ja/*.html ${RUBY_DOCDIR}/tmail/ja
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tmail/data
	${INSTALL_DATA} ${WRKSRC}/sample/*.rb ${RUBY_EXAMPLESDIR}/tmail
	${INSTALL_DATA} ${WRKSRC}/sample/data/* ${RUBY_EXAMPLESDIR}/tmail/data

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
