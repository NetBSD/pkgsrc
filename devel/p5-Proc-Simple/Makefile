# $NetBSD: Makefile,v 1.19 2016/06/08 19:23:26 wiz Exp $
#

DISTNAME=	Proc-Simple-1.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Proc-Simple/
COMMENT=	Launch and control background processes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Proc/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
