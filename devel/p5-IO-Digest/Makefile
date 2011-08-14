# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:10 obache Exp $

DISTNAME=	IO-Digest-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=OurNet/CLKAO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module to calculate digests while reading or writing

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-PerlIO-via-dynamic-[0-9]*:../../devel/p5-PerlIO-via-dynamic

PERL5_PACKLIST=		auto/IO/Digest/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
