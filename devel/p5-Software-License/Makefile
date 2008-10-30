# $NetBSD: Makefile,v 1.1.1.1 2008/10/30 23:46:32 he Exp $
#

DISTNAME=	Software-License-0.008
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/R/RJ/RJBS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Software-License/
COMMENT=	Perl 5 module which provide templated software licenses

DEPENDS+=	p5-Data-Section>0:../../devel/p5-Data-Section
DEPENDS+=	p5-Sub-Install>0:../../devel/p5-Sub-Install
DEPENDS+=	p5-Text-Template>0:../../textproc/p5-Text-Template

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Software/License/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
