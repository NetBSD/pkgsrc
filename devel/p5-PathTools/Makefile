# $NetBSD: Makefile,v 1.36 2025/07/04 08:46:26 wiz Exp $

DISTNAME=	PathTools-3.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/X/XS/XSAWYERX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/PathTools
COMMENT=	Perl module for portably manipulating file specifications
LICENSE=	${PERL5_LICENSE}

CONFLICTS+=	p5-File-Spec-[0-9]*

CFLAGS+=	-DHAS_GETCWD

PERL5_PACKLIST=	auto/Cwd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
