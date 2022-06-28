# $NetBSD: Makefile,v 1.4 2022/06/28 11:35:42 wiz Exp $

DISTNAME=		Crypt-HSXKPasswd-v3.6
PKGNAME=		p5-${DISTNAME:S/-v/-/}
PKGREVISION=		3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.bartbusschots.ie/s/publications/software/xkpasswd/
COMMENT=		Generate secure, memorable, and easy to share passwords
LICENSE=		2-clause-bsd

DEPENDS+=		p5-File-Share-[0-9]*:../../devel/p5-File-Share
DEPENDS+=		p5-Readonly-[0-9]*:../../devel/p5-Readonly
DEPENDS+=		p5-Clone-[0-9]*:../../devel/p5-Clone
DEPENDS+=		p5-DateTime-[0-9]*:../../time/p5-DateTime
DEPENDS+=		p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=		p5-File-ShareDir-[0-9]*:../../devel/p5-File-ShareDir
DEPENDS+=		p5-JSON-[0-9]*:../../converters/p5-JSON
DEPENDS+=		p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=		p5-Math-Round-[0-9]*:../../math/p5-Math-Round
DEPENDS+=		p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode
#DEPENDS+=		p5-Type-Library-[0-9]*:../../devel/p5-Type-Library
#DEPENDS+=		p5-Type-Params-[0-9]*:../../devel/p5-Type-Params
DEPENDS+=		p5-Type-Tiny-[0-9]*:../../devel/p5-Type-Tiny
#DEPENDS+=		p5-Types-Standard-[0-9]*:../../devel/p5-Types-Standard

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/HSXKPasswd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
