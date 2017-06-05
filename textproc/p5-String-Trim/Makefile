# $NetBSD: Makefile,v 1.3 2017/06/05 14:24:46 ryoon Exp $

DISTNAME=	String-Trim-0.005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=String/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~doherty/String-Trim/
COMMENT=	Perl5 module to trim whitespace from your strings
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	p5-Sub-Exporter>=0.953:../../devel/p5-Sub-Exporter
#DEPENDS+=	p5-Sub-Install>=0.030:../../devel/p5-Sub-Install

PERL5_PACKLIST=		auto/String/Trim/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
