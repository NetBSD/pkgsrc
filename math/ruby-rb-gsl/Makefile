# $NetBSD: Makefile,v 1.1.1.1 2007/12/17 23:37:49 minskim Exp $

DISTNAME=	rb-gsl-1.9.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	math ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/23975/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rb-gsl.rubyforge.org/
COMMENT=	Ruby interface to the GNU Scientific Library

USE_RUBY_SETUP=	yes

.include "../../lang/ruby/modules.mk"
.include "../../math/gsl/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/gsl
	${INSTALL_DATA} ${WRKSRC}/README ${RUBY_DOCDIR}/gsl
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${RUBY_DOCDIR}/gsl
	${INSTALL_DATA_DIR} ${RUBY_EXAMPLESDIR}/gsl
	${CP} -R ${WRKSRC}/samples/* ${RUBY_EXAMPLESDIR}/gsl
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${RUBY_EXAMPLESDIR}/gsl
	${FIND} ${RUBY_EXAMPLESDIR}/gsl -type d -print |		\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_EXAMPLESDIR}/gsl -type f -print |		\
		${XARGS} ${CHMOD} ${SHAREMODE}

.include "../../mk/bsd.pkg.mk"
