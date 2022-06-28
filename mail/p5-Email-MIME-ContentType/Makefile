# $NetBSD: Makefile,v 1.26 2022/06/28 11:34:25 wiz Exp $

DISTNAME=		Email-MIME-ContentType-1.026
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		mail perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Email-MIME-ContentType
COMMENT=		Perl module for parsing a MIME Content-Type header
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Text-Unidecode-[0-9]*:../../textproc/p5-Text-Unidecode

PERL5_PACKLIST=		auto/Email/MIME/ContentType/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
