# $NetBSD: Makefile,v 1.5 2004/03/16 02:01:11 taca Exp $
# FreeBSD: ports/mail/ruby-tmail/Makefile,v 1.10 2001/01/27 09:46:32 knu Exp

DISTNAME=	tmail-0.10.8
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	mail ruby
MASTER_SITES=	http://www.loveruby.net/archive/tmail/

MAINTAINER=	taca@NetBSD.org
HOMEPAGE=	http://www.loveruby.net/en/tmail.html
COMMENT=	Mail manipulating library for Ruby including MIME multipart support

DIST_SUBDIR=	ruby

USE_RUBY_SETUP=	# defined

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

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
