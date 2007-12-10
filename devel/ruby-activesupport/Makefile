# $NetBSD: Makefile,v 1.11.6.1 2007/12/10 17:08:10 ghen Exp $

DISTNAME=	activesupport-1.4.4
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/26548/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activesupport/
COMMENT=	Collection of classes and extensions for Rails

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../lang/ruby/modules.mk"

pre-install:
	${FIND} ${WRKSRC} -name '*.orig' -print | ${XARGS} ${RM} -f

do-install:
	${CP} -R ${WRKSRC}/lib/* ${RUBY_SITELIBDIR}
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${RUBY_SITELIBDIR}/active_support*
	${FIND} ${RUBY_SITELIBDIR}/active_support -type d		\
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${RUBY_SITELIBDIR}/active_support* -type f		\
		-exec ${CHMOD} ${LIBMODE} {} \;
	${INSTALL_DATA_DIR} ${RUBY_DOCDIR}/active_support
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
		${RUBY_DOCDIR}/active_support
	${INSTALL_DATA} ${WRKSRC}/README \
		${RUBY_DOCDIR}/active_support

.include "../../mk/bsd.pkg.mk"
