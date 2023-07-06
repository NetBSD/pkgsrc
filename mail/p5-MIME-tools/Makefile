# $NetBSD: Makefile,v 1.66 2023/07/06 09:40:46 wiz Exp $

DISTNAME=	MIME-tools-5.510
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MIME/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MIME-tools
COMMENT=	Perl5 modules for encoding and decoding MIME messages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-IO-stringy-[0-9]*:../../devel/p5-IO-stringy
DEPENDS+=	p5-MailTools-[0-9]*:../../mail/p5-MailTools
DEPENDS+=	p5-Convert-BinHex-[0-9]*:../../converters/p5-Convert-BinHex

TOOL_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/MIME/Tools/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
