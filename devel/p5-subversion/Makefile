# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 15:13:58 epg Exp $

PKGNAME=	p5-subversion-${SVNVER}
COMMENT=	Perl bindings for Subversion

.include "../../devel/subversion/Makefile.common"

PERL_DIR=		${WRKSRC}/subversion/bindings/swig/perl
ALL_TARGET=		swig-pl-lib
INSTALL_TARGET=		install-swig-pl-lib
PERL5_CONFIGURE=	NO
PERL5_CONFIGURE_DIRS=	${PERL_DIR}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/_Core/.packlist

post-build: perl5-configure
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${PERL_DIR} && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

post-install:
	${_PKG_SILENT}${_PKG_DEBUG}${_ULIMIT_CMD}cd ${PERL_DIR} && \
		${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS} install

.include "../../devel/subversion/buildlink2.mk"
.include "../../devel/swig-build/buildlink2.mk"
.include "../../devel/swig-perl/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
