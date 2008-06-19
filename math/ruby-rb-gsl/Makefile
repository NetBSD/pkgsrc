# $NetBSD: Makefile,v 1.2 2008/06/19 14:51:16 taca Exp $

DISTNAME=	rb-gsl-1.9.2
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math ruby
MASTER_SITES=	http://rubyforge.org/frs/download.php/23975/

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://rb-gsl.rubyforge.org/
COMMENT=	Ruby interface to the GNU Scientific Library

USE_RUBY_SETUP=	yes
USE_TOOLS=	pax
CONFIGURE_ARGS+=	--siteruby=${PREFIX}/${RUBY_VENDORLIB_BASE} \
			--siterubyver=${PREFIX}/${RUBY_VENDORLIB} \
			--siterubyverarch=${PREFIX}/${RUBY_VENDORARCHLIB}

INSTALLATION_DIRS=	${RUBY_DOC}/gsl ${RUBY_EG}/gsl

.include "../../lang/ruby/modules.mk"
.include "../../math/gsl/buildlink3.mk"

post-patch:
	cd ${WRKSRC}/samples; \
		${FIND} . -type d -exec ${CHMOD} ${PKGDIRMODE} {} \; ;\
		${FIND} . -type f -exec ${CHMOD} ${SHAREMODE} {} \;

post-install:
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/${RUBY_DOC}/gsl
	${INSTALL_DATA} ${WRKSRC}/html/*.html ${DESTDIR}${PREFIX}/${RUBY_DOC}/gsl
	cd ${WRKSRC}/samples; ${PAX} -rw . ${DESTDIR}${PREFIX}/${RUBY_EG}/gsl
	${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DESTDIR}${PREFIX}/${RUBY_EG}/gsl

.include "../../mk/bsd.pkg.mk"
