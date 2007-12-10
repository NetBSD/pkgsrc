# $NetBSD: Makefile,v 1.8.6.1 2007/12/10 17:08:11 ghen Exp $

DISTNAME=	actionmailer-1.3.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/26557/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionmailer/
COMMENT=	Ruby framework for designing email-service layers

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=1.13.5:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-tmail>=0.10.8:../../mail/ruby-tmail

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
