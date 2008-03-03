# $NetBSD: Makefile,v 1.14 2008/03/03 17:45:37 jlam Exp $

DISTNAME=	activesupport-2.0.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=	devel ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/29345/
EXTRACT_SUFX=	.tgz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/activesupport/
COMMENT=	Collection of classes and extensions for Rails

PKG_DESTDIR_SUPPORT=	destdir

NO_BUILD=	yes
NO_CONFIGURE=	yes

.include "../../lang/ruby/modules.mk"

pre-install:
	${FIND} ${WRKSRC} -name \*.orig -exec ${RM} -f {} \;

do-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${RUBY_SITELIBDIR}
	${CP} -R ${WRKSRC}/lib/* ${DESTDIR}${RUBY_SITELIBDIR}
	${CHOWN} -R ${LIBOWN}:${LIBGRP} ${DESTDIR}${RUBY_SITELIBDIR}/active_support*
	${FIND} ${DESTDIR}${RUBY_SITELIBDIR}/active_support -type d		\
		-exec ${CHMOD} ${PKGDIRMODE} {} \;
	${FIND} ${DESTDIR}${RUBY_SITELIBDIR}/active_support* -type f		\
		-exec ${CHMOD} ${LIBMODE} {} \;
	${INSTALL_DATA_DIR} ${DESTDIR}${RUBY_DOCDIR}/active_support
	${INSTALL_DATA} ${WRKSRC}/CHANGELOG \
		${DESTDIR}${RUBY_DOCDIR}/active_support
	${INSTALL_DATA} ${WRKSRC}/README \
		${DESTDIR}${RUBY_DOCDIR}/active_support

.include "../../mk/bsd.pkg.mk"
