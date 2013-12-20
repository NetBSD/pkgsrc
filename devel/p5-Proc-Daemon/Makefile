# $NetBSD: Makefile,v 1.20 2013/12/20 15:43:51 wen Exp $
#

DISTNAME=	Proc-Daemon-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
SVR4_PKGNAME=	p5prd
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mhonarc.org/~ehood/earlsperls.html
COMMENT=	Provide capability for a Perl program to run as a daemon
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS=	p5-Proc-ProcessTable>=0:../../devel/p5-Proc-ProcessTable

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Proc/Daemon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
