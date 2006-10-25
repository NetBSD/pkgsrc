# $NetBSD: Makefile,v 1.9 2006/10/25 13:34:03 obache Exp $

DISTNAME=	Data-FormValidator-4.40
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-FormValidator/
COMMENT=	Validates user input based on input profile

DEPENDS+=	p5-Date-Calc-[0-9]*:../../devel/p5-Date-Calc
DEPENDS+=	p5-File-MMagic>=1.17:../../misc/p5-File-MMagic
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-MIME-Types>=1.005:../../mail/p5-MIME-Types
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common
DEPENDS+=	{p5-Test-Simple>=0.10,perl>=5.7.2}:../../devel/p5-Test-Simple

PERL5_PACKLIST=		auto/Data/FormValidator/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
