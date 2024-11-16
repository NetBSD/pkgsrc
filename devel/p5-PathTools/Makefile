# $NetBSD: Makefile,v 1.35 2024/11/16 12:04:55 wiz Exp $

DISTNAME=	PathTools-3.75
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
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
