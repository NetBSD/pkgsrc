# $NetBSD: Makefile,v 1.58 2018/08/22 09:45:30 wiz Exp $

DISTNAME=	MIME-tools-5.509
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/MIME-tools/
COMMENT=	Perl5 modules for encoding and decoding MIME messages
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.9.5,p5-File-Temp>=0.18}:../../devel/p5-File-Temp
DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
#DEPENDS+=	{perl>=5.8.6,p5-MIME-Base64>=3.03}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
# missing dependency in Makefile, see
# https://rt.cpan.org/Public/Bug/Display.html?id=72223
DEPENDS+=	p5-Convert-BinHex-[0-9]*:../../converters/p5-Convert-BinHex
# actually, test dependency
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/Tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
