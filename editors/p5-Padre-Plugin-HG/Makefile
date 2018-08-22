# $NetBSD: Makefile,v 1.12 2018/08/22 09:45:03 wiz Exp $

DISTNAME=	Padre-Plugin-HG-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	editors perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Padre/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Padre-Plugin-HG/
COMMENT=	Mecurial interface for Padre
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.03:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Padre>=0.47:../../editors/p5-Padre
DEPENDS+=	mercurial-[0-9]*:../../devel/mercurial

PERL5_PACKLIST=		auto/Padre/Plugin/HG/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
