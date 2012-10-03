# $NetBSD: Makefile,v 1.2 2012/10/03 21:55:46 wiz Exp $

DISTNAME=		Test-Trap-v0.2.1
PKGNAME=		p5-${DISTNAME:S/v0/0/}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Trap/
COMMENT=		Perl extension to trap exit codes, exceptions, output
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Data-Dump-[0-9]*:../../devel/p5-Data-Dump
DEPENDS+=		p5-Test-Tester>=0.107:../../devel/p5-Test-Tester

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Test/Trap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
