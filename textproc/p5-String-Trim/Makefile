# $NetBSD: Makefile,v 1.6 2019/08/11 13:23:39 wiz Exp $

DISTNAME=	String-Trim-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/String-Trim
COMMENT=	Perl5 module to trim whitespace from your strings
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Sub-Exporter>=0.953:../../devel/p5-Sub-Exporter
#DEPENDS+=	p5-Sub-Install>=0.030:../../devel/p5-Sub-Install

PERL5_PACKLIST=		auto/String/Trim/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
