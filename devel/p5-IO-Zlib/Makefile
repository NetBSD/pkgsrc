# $NetBSD: Makefile,v 1.3 2003/06/02 01:20:28 jschauma Exp $

DISTNAME=		IO-Zlib-1.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5izl
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=		tech-pkg@netbsd.org
COMMENT=		perl5 IO:: style interface to Compress::Zlib

DEPENDS+=		p5-Compress-Zlib>=1.16:../../devel/p5-Compress-Zlib

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/IO/Zlib/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
