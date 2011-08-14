# $NetBSD: Makefile,v 1.3 2011/08/14 14:14:48 obache Exp $
#

DISTNAME=	RT-Client-REST-0.41
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=RT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/RT-Client-REST/
COMMENT=	Perl 5 module to talk to RT using REST protocol
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/RT/Client/REST/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
DEPENDS+=	p5-Error-[0-9]*:../../devel/p5-Error
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Params-Validate-[0-9]*:../../devel/p5-Params-Validate

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
