# $NetBSD: Makefile,v 1.11 2019/08/11 13:20:25 wiz Exp $

DISTNAME=		Term-Encoding-0.03
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=		hiramatu@boreas.dti.ne.jp
HOMEPAGE=		https://metacpan.org/release/Term-Encoding
COMMENT=		Detect encoding of the current terminal
LICENSE=		${PERL5_LICENSE}

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/Term/Encoding/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
