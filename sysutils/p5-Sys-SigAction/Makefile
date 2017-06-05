# $NetBSD: Makefile,v 1.14 2017/06/05 14:24:37 ryoon Exp $

DISTNAME=	Sys-SigAction-0.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-SigAction
COMMENT=	Perl extension for Consistent Signal Handling
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Sys/SigAction/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
