# $NetBSD: Makefile,v 1.6 2006/10/09 06:17:20 minskim Exp $

DISTNAME=	activerecord-1.14.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/12246/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ar.rubyonrails.org/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.3.1:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes
EXAMPLES=		associations.png associations.rb shared_setup.rb \
			validation.rb

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/active_record/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/activerecord
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/activerecord
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/activerecord
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/activerecord
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${RUBY_EXAMPLESDIR}/activerecord
.endfor

.include "../../mk/bsd.pkg.mk"
