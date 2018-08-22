# $NetBSD: Makefile,v 1.2 2018/08/22 09:44:15 wiz Exp $

DISTNAME=	Menlo-1.9019
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Menlo
COMMENT=	A CPAN client
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-CPAN-Common-Index-[0-9]*:../../devel/p5-CPAN-Common-Index
DEPENDS+=	p5-CPAN-DistnameInfo-[0-9]*:../../devel/p5-CPAN-DistnameInfo
DEPENDS+=	p5-CPAN-Meta-Check-[0-9]*:../../devel/p5-CPAN-Meta-Check
DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Class-Tiny-[0-9]*:../../devel/p5-Class-Tiny
DEPENDS+=	p5-ExtUtils-Config-[0-9]*:../../devel/p5-ExtUtils-Config
DEPENDS+=	p5-ExtUtils-Helpers-[0-9]*:../../devel/p5-ExtUtils-Helpers
DEPENDS+=	p5-ExtUtils-InstallPaths-[0-9]*:../../devel/p5-ExtUtils-InstallPaths
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-File-pushd-[0-9]*:../../devel/p5-File-pushd
DEPENDS+=	p5-HTTP-Tinyish-[0-9]*:../../www/p5-HTTP-Tinyish
DEPENDS+=	p5-Module-CPANfile-[0-9]*:../../devel/p5-Module-CPANfile
DEPENDS+=	p5-Parse-PMFile-[0-9]*:../../devel/p5-Parse-PMFile
DEPENDS+=	p5-String-ShellQuote-[0-9]*:../../textproc/p5-String-ShellQuote
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-Win32-ShellQuote-[0-9]*:../../textproc/p5-Win32-ShellQuote
DEPENDS+=	p5-local-lib-[0-9]*:../../devel/p5-local-lib

PERL5_PACKLIST=	auto/Menlo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
