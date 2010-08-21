# $NetBSD: Makefile,v 1.10 2010/08/21 16:33:51 seb Exp $

DISTNAME=	IO-Digest-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
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
