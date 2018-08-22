# $NetBSD: Makefile,v 1.21 2018/08/22 09:44:00 wiz Exp $

DISTNAME=	File-Find-Rule-0.34
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	hiramatu@boreas.dti.ne.jp
HOMEPAGE=	http://search.cpan.org/dist/File-Find-Rule/
COMMENT=	Alternative interface to File::Find
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Number-Compare>=0.01:../../math/p5-Number-Compare
DEPENDS+=	p5-Text-Glob>=0.07:../../textproc/p5-Text-Glob

PERL5_PACKLIST=		auto/File/Find/Rule/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
