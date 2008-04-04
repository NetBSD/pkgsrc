# $NetBSD: Makefile,v 1.18 2008/04/04 15:31:39 jlam Exp $

PKGNAME=	${RUBY_PKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Ruby bindings for Subversion

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

REPLACE_RUBY_DIRS=	tools

CONFIGURE_ENV+=		RUBY=${RUBY:Q}

BUILD_TARGET=		swig-rb-lib swig-rb
INSTALL_TARGET=		install-swig-rb

TEST_TARGET=		check-swig-rb

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

post-install:
	${RM} ${RUBY_SITEARCHLIBDIR}/svn/ext/*.la
	${INSTALL_DATA_DIR} ${SVNEXAMPLES}/ruby
	${INSTALL_DATA} ${WRKSRC}/tools/*/*.rb ${SVNEXAMPLES}/ruby

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
