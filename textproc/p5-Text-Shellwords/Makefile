# $NetBSD: Makefile,v 1.24 2020/08/31 18:12:04 wiz Exp $
#

DISTNAME=		Text-Shellwords-1.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		https://metacpan.org/release/Text-Shellwords
COMMENT=		Wrapper around shellwords.pl package

PERL5_PACKLIST=		auto/Text/Shellwords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
