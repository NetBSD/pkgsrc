# $NetBSD: Makefile,v 1.4 2005/11/02 14:28:45 taca Exp $

DISTNAME=	activerecord-1.12.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/6569/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://ar.rubyonrails.org/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport-[0-9]*:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes
EXAMPLES=		associations.png associations.rb shared_setup.rb \
			validation.rb

post-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}/active_record/support
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/active_record
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/activerecord
.for f in ${EXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/examples/${f} \
		${RUBY_EXAMPLESDIR}/activerecord
.endfor

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
