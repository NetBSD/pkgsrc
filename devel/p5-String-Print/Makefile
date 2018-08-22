# $NetBSD: Makefile,v 1.11 2018/08/22 09:44:39 wiz Exp $

DISTNAME=		String-Print-0.93
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/String-Print/
COMMENT=		Perl 5 module providing a printf alternative
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Unicode-LineBreak-[0-9]*:../../textproc/p5-Unicode-LineBreak
DEPENDS+=		p5-TimeDate-[0-9]*:../../time/p5-TimeDate
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/String/Print/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
