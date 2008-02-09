# $NetBSD: Makefile,v 1.11 2008/02/09 06:20:25 minskim Exp $

DISTNAME=	activerecord-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	databases ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29348/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activerecord/
COMMENT=	Object-relation mapping put on rails

DEPENDS+=	${RUBY_PKGPREFIX}-activesupport>=2.0.2:../../devel/ruby-activesupport

NO_BUILD=		yes
NO_CONFIGURE=		yes
USE_RUBY_INSTALL=	yes
EXAMPLES=		associations.png

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
