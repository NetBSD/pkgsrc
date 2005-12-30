# $NetBSD: Makefile,v 1.5 2005/12/30 13:17:51 joerg Exp $

DISTNAME=	activesupport-1.2.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/6566/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://as.rubyonrails.com/
COMMENT=	Collection of classes and extensions for Rails

NO_BUILD=	yes
NO_CONFIGURE=	yes

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${RUBY_SITELIBDIR}/active_support*
	${FIND} ${RUBY_SITELIBDIR}/active_support -type d		\
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${RUBY_SITELIBDIR}/active_support* -type f		\
		-exec ${CHMOD} ${LIBMODE} {} \;
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
		${RUBY_DOCDIR}/CHANGELOG.activesupport

.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
