# $NetBSD: Makefile,v 1.16 2021/05/24 19:50:42 wiz Exp $

DISTNAME=	File-Path-Expand-1.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	13
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Path-Expand
COMMENT=	Perl 5 module to expand filenames
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/Path/Expand/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
