# $NetBSD: Makefile,v 1.8 2023/07/06 09:41:58 wiz Exp $

DISTNAME=	Tie-Handle-Offset-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-Handle-Offset
COMMENT=	Tied handle that hides the beginning of a file
LICENSE=	apache-2.0

PERL5_PACKLIST=	auto/Tie/Handle/Offset/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
