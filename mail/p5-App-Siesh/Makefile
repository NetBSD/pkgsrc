# $NetBSD: Makefile,v 1.3 2011/08/14 13:25:22 obache Exp $

DISTNAME=	App-Siesh-0.20
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MD/MDOM/}

MAINTAINER=	dom@math.uni-bonn.de
HOMEPAGE=	http://www.math.uni-bonn.de/people/dom/
COMMENT=	Sieve Shell
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Config-Find-[0-9]*:../../devel/p5-Config-Find
DEPENDS+=	p5-Config-Tiny-[0-9]*:../../devel/p5-Config-Tiny
DEPENDS+=	p5-IO-Interactive>=0.0.5:../../devel/p5-IO-Interactive
DEPENDS+=	p5-IO-Prompt-[0-9]*:../../devel/p5-IO-Prompt
DEPENDS+=	p5-IPC-System-Simple-[0-9]*:../../devel/p5-IPC-System-Simple
DEPENDS+=	p5-Net-ManageSieve-[0-9]*:../../mail/p5-Net-ManageSieve
DEPENDS+=	p5-Term-ShellUI>=0.86:../../devel/p5-Term-ShellUI
DEPENDS+=	p5-autodie-[0-9]*:../../devel/p5-autodie
DEPENDS+=	p5-parent-[0-9]*:../../devel/p5-parent

BUILD_DEPENDS+=	p5-IO-String-[0-9]*:../../devel/p5-IO-String
BUILD_DEPENDS+=	p5-Test-Output-[0-9]*:../../devel/p5-Test-Output

# recommends
DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/App/Siesh/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
