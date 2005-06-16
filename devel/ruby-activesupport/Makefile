# $NetBSD: Makefile,v 1.2 2005/06/16 06:57:48 jlam Exp $

DISTNAME=	activesupport-1.0.3
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/3678/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://as.rubyonrails.com/
COMMENT=	Collection of classes and extensions for Rails

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../lang/ruby/modules.mk"

do-install:
	${INSTALL_DATA_DIR} ${RUBY_SITELIBDIR}
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${RUBY_SITELIBDIR}/active_support*
	${FIND} ${RUBY_SITELIBDIR}/active_support -type d -print |	\
		${XARGS} ${CHMOD} ${PKGDIRMODE}
	${FIND} ${RUBY_SITELIBDIR}/active_support* -type f -print |	\
		${XARGS} ${CHMOD} ${LIBMODE}

.include "../../mk/bsd.pkg.mk"
