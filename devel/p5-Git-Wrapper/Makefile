# $NetBSD: Makefile,v 1.26 2023/07/06 09:39:16 wiz Exp $

DISTNAME=		Git-Wrapper-0.048
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		6
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Git-Wrapper
COMMENT=		Wrap git(7) command-line interface
LICENSE=		${PERL5_LICENSE}

TOOL_DEPENDS+=		p5-Env-Path-[0-9]*:../../devel/p5-Env-Path
#TOOL_DEPENDS+=	{perl>=5.001,p5-File-Path-[0-9]*}:../../devel/p5-File-Path
TOOL_DEPENDS+=		p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep
TOOL_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TOOL_DEPENDS+=		p5-Test-Most-[0-9]*:../../devel/p5-Test-Most

#DEPENDS+=		{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=		p5-Devel-CheckBin-[0-9]*:../../devel/p5-Devel-CheckBin
DEPENDS+=		p5-File-chdir>=0.1010:../../devel/p5-File-chdir
#DEPENDS+=		{perl>=5.9.5,p5-IPC-Cmd-[0-9]*}:../../devel/p5-IPC-Cmd
DEPENDS+=		p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
DEPENDS+=		git-base-[0-9]*:../../devel/git-base

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Wrapper/.packlist

USE_TOOLS+=		perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
