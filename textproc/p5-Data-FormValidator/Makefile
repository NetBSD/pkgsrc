# $NetBSD: Makefile,v 1.28 2017/06/05 14:24:39 ryoon Exp $

DISTNAME=	Data-FormValidator-4.86
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5 textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Data-FormValidator/
COMMENT=	Validates user input based on input profile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Date-Calc>=5.0:../../devel/p5-Date-Calc
DEPENDS+=	p5-Email-Valid-[0-9]*:../../mail/p5-Email-Valid
DEPENDS+=	p5-File-MMagic>=1.17:../../misc/p5-File-MMagic
DEPENDS+=	p5-Image-Size-[0-9]*:../../graphics/p5-Image-Size
DEPENDS+=	p5-MIME-Types>=1.005:../../mail/p5-MIME-Types
DEPENDS+=	p5-Perl6-Junction-[0-9]*:../../devel/p5-Perl6-Junction
DEPENDS+=	p5-Regexp-Common-[0-9]*:../../textproc/p5-Regexp-Common

BUILD_DEPENDS+=	p5-CGI>=3.48:../../www/p5-CGI

PERL5_REQD+=	5.8.0

PERL5_PACKLIST=		auto/Data/FormValidator/.packlist
#PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
