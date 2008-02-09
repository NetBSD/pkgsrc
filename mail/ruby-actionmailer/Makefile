# $NetBSD: Makefile,v 1.10 2008/02/09 06:24:57 minskim Exp $

DISTNAME=	actionmailer-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	mail ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29354/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/actionmailer/
COMMENT=	Ruby framework for designing email-service layers

DEPENDS+=	${RUBY_PKGPREFIX}-actionpack>=2.0.2:../../www/ruby-actionpack
DEPENDS+=	${RUBY_PKGPREFIX}-tmail>=1.1.0:../../mail/ruby-tmail

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes

.include "../../lang/ruby/modules.mk"

pre-install:
	${RM} -rf ${WRKSRC}/lib/action_mailer/vendor/tmail-1.1.0
	${RM} -f ${WRKSRC}/lib/action_mailer/vendor/tmail.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/actionmailer
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/actionmailer
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/actionmailer

.include "../../mk/bsd.pkg.mk"
