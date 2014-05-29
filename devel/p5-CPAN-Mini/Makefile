# $NetBSD: Makefile,v 1.2 2014/05/29 23:35:41 wiz Exp $

DISTNAME=	CPAN-Mini-1.111015
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CPAN/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/CPAN-Mini/
COMMENT=	Create a minimal mirror of CPAN
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-HomeDir>=0.57:../../devel/p5-File-HomeDir
DEPENDS+=	p5-libwww>=5:../../www/p5-libwww
DEPENDS+=	p5-URI>=1:../../www/p5-URI

PERL5_PACKLIST=		auto/CPAN/Mini/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
