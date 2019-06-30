# $NetBSD: Makefile,v 1.18 2019/06/30 20:15:04 nia Exp $

DISTNAME=	File-pushd-1.016
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-pushd
COMMENT=	Perl module to change directory temporarily for a limited scope
LICENSE=	apache-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/pushd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
