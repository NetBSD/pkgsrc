# $NetBSD: Makefile,v 1.13 2017/06/05 14:24:24 ryoon Exp $
#

DISTNAME=	RT-Client-REST-0.50
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RT-Client-REST/
COMMENT=	Perl 5 module to talk to RT using REST protocol
LICENSE=	artistic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/RT/Client/REST/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

# for make test
BUILD_DEPENDS+=	p5-DateTime-Format-DateParse-[0-9]*:../../time/p5-DateTime-Format-DateParse
BUILD_DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime
BUILD_DEPENDS+=	p5-CGI-[0-9]*:../../www/p5-CGI

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
