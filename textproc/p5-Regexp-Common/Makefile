# $NetBSD: Makefile,v 1.33 2019/08/11 13:23:37 wiz Exp $

DISTNAME=		Regexp-Common-2017060201
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Regexp/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Regexp-Common
COMMENT=		Provide commonly requested regular expressions
LICENSE=		mit OR modified-bsd OR artistic OR artistic-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Regexp/Common/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
