# $NetBSD: Makefile,v 1.29 2018/08/22 09:47:00 wiz Exp $

DISTNAME=		Text-Kakasi-2.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		japanese textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Text-Kakasi/
COMMENT=		Perl5 module to use Kakasi
LICENSE=		gnu-gpl-v2

PERL5_PACKLIST=		auto/Text/Kakasi/.packlist

.include "../../textproc/kakasi/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
