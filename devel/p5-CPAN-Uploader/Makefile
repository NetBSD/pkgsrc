# $NetBSD: Makefile,v 1.29 2023/12/13 13:48:30 mef Exp $

DISTNAME=	CPAN-Uploader-0.103018
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CPAN-Uploader
COMMENT=	Perl 5 module to upload things to the CPAN
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-Getopt-Long-Descriptive>=0.084:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=		p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=		p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=		p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/Uploader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
