# $NetBSD: Makefile,v 1.20 2019/08/11 13:20:14 wiz Exp $

DISTNAME=		Proc-Pidfile-1.09
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Proc/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Proc-Pidfile
COMMENT=		Perl module for maintaining a pid file
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Proc/Pidfile/.packlist

DEPENDS+=		p5-Proc-ProcessTable>=0.41:../../devel/p5-Proc-ProcessTable

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
