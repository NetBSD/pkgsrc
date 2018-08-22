# $NetBSD: Makefile,v 1.21 2018/08/22 09:47:02 wiz Exp $
#

DISTNAME=		Text-Shellwords-1.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://search.cpan.org/dist/Text-Shellwords/
COMMENT=		Wrapper around shellwords.pl package

PERL5_PACKLIST=		auto/Text/Shellwords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
