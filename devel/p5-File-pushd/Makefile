# $NetBSD: Makefile,v 1.7 2012/10/31 11:18:14 asau Exp $

DISTNAME=	File-pushd-1.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/File-pushd/
COMMENT=	Perl module to change directory temporarily for a limited scope
LICENSE=	apache-2.0

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/File/pushd/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
