# $NetBSD: Makefile,v 1.27 2015/09/06 04:04:49 mef Exp $
#

DISTNAME=	Proc-Daemon-0.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/~ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-Proc-ProcessTable>=0:../../devel/p5-Proc-ProcessTable

PERL5_PACKLIST=		auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
