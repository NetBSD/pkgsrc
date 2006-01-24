# $NetBSD: Makefile,v 1.15 2006/01/24 07:32:04 wiz Exp $

DISTNAME=	SVN-Mirror-0.67
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Mirrors one Subversion repository to another

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	p5-subversion>=1.0.7:../../devel/p5-subversion
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Data-UUID>=0.11:../../devel/p5-Data-UUID
DEPENDS+=	p5-SVN-Simple>=0.26:../../devel/p5-SVN-Simple
DEPENDS+=	p5-File-chdir>=0.06:../../devel/p5-File-chdir
DEPENDS+=	p5-Class-Accessor>=0.19:../../devel/p5-Class-Accessor

PERL5_PACKLIST=		auto/SVN/Mirror/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
