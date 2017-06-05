# $NetBSD: Makefile,v 1.10 2017/06/05 14:23:08 ryoon Exp $
#

DISTNAME=		IPC-Signal-1.00
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=IPC/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/IPC-Signal/
COMMENT=		Perl5 extension to deal with signals
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/IPC/Signal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
