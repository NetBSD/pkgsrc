# $NetBSD: Makefile,v 1.21 2014/05/29 23:36:14 wiz Exp $
#

DISTNAME=	Proc-Daemon-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
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
