# $NetBSD: Makefile,v 1.5 2006/10/09 23:09:44 minskim Exp $

DISTNAME=	actionmailer-1.2.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/12317/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://am.rubyonrails.org/
COMMENT=	Ruby framework for designing email-service layers

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=1.12.5:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-tmail>=0.10.7:../../mail/ruby-tmail

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

pre-install:
	${RM} -rf ${WRKSRC}/lib/action_mailer/vendor/tmail
	${RM} -f ${WRKSRC}/lib/action_mailer/vendor/tmail.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionmailer
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/actionmailer
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionmailer

.include "../../mk/bsd.pkg.mk"
