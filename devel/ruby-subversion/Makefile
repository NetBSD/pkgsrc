# $NetBSD: Makefile,v 1.57 2016/03/05 11:28:26 jperkin Exp $

PKGNAME=	${RUBY_PKGPREFIX}-subversion-${SVNVER}
PKGREVISION=	1
COMMENT=	Ruby bindings for Subversion

.include "../../devel/subversion/Makefile.common"

SHLIBTOOL_OVERRIDE=	# empty

REPLACE_RUBY_DIRS=	tools

CONFIGURE_ENV+=		RUBY=${RUBY:Q}
CONFIGURE_ARGS+=	--with-ruby-sitedir=${PREFIX}/${RUBY_VENDORLIB_BASE}

BUILD_TARGET=		swig-rb
INSTALL_TARGET=		install-swig-rb

TEST_TARGET=		check-swig-rb

INSTALLATION_DIRS+=	${SVNEXAMPLES:S/${PREFIX}\///}/ruby

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

post-install:
	${RM} ${DESTDIR}${PREFIX}/${RUBY_VENDORARCHLIB}/svn/ext/*.la
	${INSTALL_DATA} ${WRKSRC}/tools/*/*.rb ${DESTDIR}${SVNEXAMPLES}/ruby

.include "../../devel/subversion-base/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
