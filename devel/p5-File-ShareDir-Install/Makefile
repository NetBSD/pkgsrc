# $NetBSD: Makefile,v 1.17 2019/06/30 20:15:03 nia Exp $

DISTNAME=	File-ShareDir-Install-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-ShareDir-Install
COMMENT=	Perl 5 module to install shared files
LICENSE=	${PERL5_LICENSE}

TEST_TARGET?=	# to skip make test (but can be enabled by 'env TEST_TARGET=test make test')

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/ShareDir/Install/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
