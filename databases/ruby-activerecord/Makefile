# $NetBSD: Makefile,v 1.9.6.1 2007/12/10 17:08:11 ghen Exp $

DISTNAME=	activerecord-1.15.5
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/26551/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activerecord/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=1.4.4:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes
EXAMPLES=		associations.png associations.rb shared_setup.rb \
			validation.rb

.include "../../lang/ruby/modules.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/active_record
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${RUBY_EXAMPLESDIR}/active_record
.endfor

.include "../../mk/bsd.pkg.mk"
