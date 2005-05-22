# $NetBSD: Makefile,v 1.19 2005/05/22 05:35:32 jlam Exp $

PKGNAME=	p5-subversion-${SVNVER}
COMMENT=	Perl bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../devel/subversion/Makefile.common"

PERL5_REQD+=		5.8
PERL_DIR=		${WRKSRC}/subversion/bindings/swig/perl
BUILD_TARGET=		swig-pl-lib swig-pl
INSTALL_TARGET=		install-swig-pl
PERL5_CONFIGURE=	NO
#PERL5_CONFIGURE_DIRS=	${PERL_DIR}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/_Core/.packlist

post-patch:
	${RM} ${WRKSRC}/build-outputs.mk
	${CP} ${FILESDIR}/build-outputs.mk ${WRKSRC}/build-outputs.mk

.include "../../devel/subversion/buildlink3.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../devel/swig-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
