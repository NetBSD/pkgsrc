# $NetBSD: Makefile,v 1.8 2019/08/11 13:19:05 wiz Exp $

DISTNAME=	Config-Any-Merge-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	perl5 devel textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Config/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Config-Any-Merge
COMMENT=	Overrinding of configuration variables based on file order
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Any>=0.15:../../devel/p5-Config-Any
DEPENDS+=	p5-Hash-Merge-[0-9]*:../../devel/p5-Hash-Merge
BUILD_DEPENDS+=	p5-Config-Tiny-[0-9]*:../../devel/p5-Config-Tiny

PERL5_PACKLIST=	auto/Config/Any/Merge/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
