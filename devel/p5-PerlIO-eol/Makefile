# $NetBSD: Makefile,v 1.26 2021/05/24 19:51:25 wiz Exp $

DISTNAME=	PerlIO-eol-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PerlIO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PerlIO-eol
COMMENT=	Perl module for normalizing line endings
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/PerlIO/eol/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
