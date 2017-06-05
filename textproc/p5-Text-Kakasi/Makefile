# $NetBSD: Makefile,v 1.28 2017/06/05 14:24:50 ryoon Exp $

DISTNAME=		Text-Kakasi-2.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
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
