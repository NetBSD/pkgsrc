# $NetBSD: Makefile,v 1.16 2015/06/12 10:51:27 wiz Exp $

DISTNAME=	Pod-Tree-1.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	textproc devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Pod-Tree/
COMMENT=	Create a static syntax tree for a POD
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-HTML-Stream>=1.49:../../www/p5-HTML-Stream
DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
DEPENDS+=	{perl>=5.9.3,p5-Pod-Escapes>=1.02}:../../textproc/p5-Pod-Escapes
DEPENDS+=	p5-Text-Template>=1.0:../../textproc/p5-Text-Template

PERL5_PACKLIST=	auto/Pod/Tree/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
