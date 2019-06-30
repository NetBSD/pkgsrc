# $NetBSD: Makefile,v 1.23 2019/06/30 20:15:37 nia Exp $

DISTNAME=	PerlIO-eol-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PerlIO-eol
COMMENT=	Perl module for normalizing line endings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PerlIO/eol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
