# $NetBSD: Makefile,v 1.14 2004/11/10 18:09:07 epg Exp $

PKGNAME=	p5-subversion-${SVNVER}
COMMENT=	Perl bindings for Subversion

PKG_INSTALLATION_TYPES=	overwrite pkgviews

.include "../../devel/subversion/Makefile.common"

CONFIGURE_ENV+=		PERL=${PERL5}

PERL5_REQD+=		5.8
PERL_DIR=		${WRKSRC}/subversion/bindings/swig/perl
ALL_TARGET=		swig-pl-lib swig-pl
INSTALL_TARGET=		install-swig-pl
PERL5_CONFIGURE=	NO
#PERL5_CONFIGURE_DIRS=	${PERL_DIR}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/SVN/_Core/.packlist

.include "../../devel/subversion/buildlink3.mk"
.include "../../devel/swig-build/buildlink3.mk"
.include "../../devel/swig-perl/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
