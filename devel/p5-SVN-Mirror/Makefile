# $NetBSD: Makefile,v 1.25 2011/08/14 12:26:34 obache Exp $

DISTNAME=	SVN-Mirror-0.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5 scm
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SVN-Mirror/
COMMENT=	Mirrors one Subversion repository to another

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-subversion>=1.2.0:../../devel/p5-subversion
DEPENDS+=	p5-URI>=1.30:../../www/p5-URI
DEPENDS+=	p5-Term-ReadKey>=2.30:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-Data-UUID>=0.11:../../devel/p5-Data-UUID
DEPENDS+=	p5-SVN-Simple>=0.27:../../devel/p5-SVN-Simple
DEPENDS+=	p5-File-chdir>=0.06:../../devel/p5-File-chdir
DEPENDS+=	p5-Class-Accessor>=0.25:../../devel/p5-Class-Accessor
DEPENDS+=	p5-TimeDate>0:../../time/p5-TimeDate

PERL5_PACKLIST=		auto/SVN/Mirror/.packlist

MAKE_ENV+=	PERL_EXTUTILS_AUTOINSTALL=--skip

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
