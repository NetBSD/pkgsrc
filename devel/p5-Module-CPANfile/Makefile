# $NetBSD: Makefile,v 1.9 2018/08/22 09:44:16 wiz Exp $

DISTNAME=	Module-CPANfile-1.1004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Module/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Module-CPANfile/
COMMENT=	Parse cpanfile
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Module/CPANfile/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
