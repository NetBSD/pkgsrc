# $NetBSD: Makefile,v 1.22 2019/06/30 20:15:38 nia Exp $
#

DISTNAME=	Proc-Simple-1.32
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Proc-Simple
COMMENT=	Launch and control background processes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Proc/Simple/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
