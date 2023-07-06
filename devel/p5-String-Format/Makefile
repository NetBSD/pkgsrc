# $NetBSD: Makefile,v 1.28 2023/07/06 09:40:02 wiz Exp $

DISTNAME=	String-Format-1.18
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

HOMEPAGE=	https://metacpan.org/release/String-Format
MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl module for sprintf-like string formatting capabilities
LICENSE=	gnu-gpl-v2

PERL5_PACKLIST=		auto/String/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
