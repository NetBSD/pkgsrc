# $NetBSD: Makefile,v 1.10 2004/03/29 18:08:33 epg Exp $

PKGNAME=	p5-subversion-${SVNVER}
COMMENT=	Perl bindings for Subversion

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ENV+=		PERL=${PERL5}

PERL5_REQD+=		5.8
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

.include "../../devel/subversion/buildlink3.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../devel/swig-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
