# $NetBSD: Makefile,v 1.1.1.1 2001/07/01 12:54:55 taca Exp $
# FreeBSD: ports/mail/ruby-tmail/Makefile,v 1.10 2001/01/27 09:46:32 knu Exp

DISTNAME=	tmail-0.9.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}${DISTNAME}
CATEGORIES=	mail
MASTER_SITES=	http://www.xdsl.ne.jp/Cd/aamine/soft/

MAINTAINER=	taca@netbsd.org
HOMEPAGE=	http://www.xdsl.ne.jp/Cd/aamine/
COMMENT=	Mail manipulating library for Ruby including MIME multipart support

DEPENDS+= 	${RUBY_PKGNAMEPREFIX}racc-runtime>=1.3.6:../../devel/ruby-racc-runtime
DEPENDS+=	${RUBY_PKGNAMEPREFIX}strscan>=0.6.1:../../devel/ruby-strscan

DIST_SUBDIR=	ruby
USE_RUBY_AMSTD=	yes
USE_RUBY_SETUP=	yes

post-patch:
	${RUBY} -i -ne '/\btmail\b/ and print' \
		${WRKSRC}/ext/PATHCONV ${WRKSRC}/lib/PATHCONV
	for d in cparse cscan; do ${RM} -rf ${WRKSRC}/ext/$$d; done
	for d in amstd raccrt strscan; do ${RM} -rf ${WRKSRC}/lib/$$d; done

post-install:
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/tmail
	${CP} -R ${WRKSRC}/sample/* ${RUBY_EXAMPLESDIR}/tmail
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/tmail/ja
	${CP} -R ${WRKSRC}/README.en ${WRKSRC}/doc.en/* ${RUBY_DOCDIR}/tmail
	${CP} -R ${WRKSRC}/README.ja ${WRKSRC}/doc.ja/* ${RUBY_DOCDIR}/tmail/ja

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
