# $NetBSD: Makefile,v 1.24 2023/07/06 09:39:14 wiz Exp $

DISTNAME=	Filesys-Notify-Simple-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Filesys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Filesys-Notify-Simple
COMMENT=	Perl5 module providing a simple and dumb file system watcher
LICENSE=	${PERL5_LICENSE}

TOOL_DEPENDS+=	p5-Test-SharedFork-[0-9]*:../../devel/p5-Test-SharedFork

PERL5_PACKLIST=		auto/Filesys/Notify/Simple/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
