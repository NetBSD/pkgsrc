# $NetBSD: Makefile,v 1.19 2018/08/22 09:43:40 wiz Exp $

DISTNAME=	CPAN-Uploader-0.103013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Uploader/
COMMENT=	Perl 5 module to upload things to the CPAN
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Getopt-Long-Descriptive>=0.084:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-HTTP-Message-[0-9]*:../../www/p5-HTTP-Message
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
#BUILD_DEPENDS+=	{perl>=5.13.4,p5-Test-Simple>=0.96}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CPAN/Uploader/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
