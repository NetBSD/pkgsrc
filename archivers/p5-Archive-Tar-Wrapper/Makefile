# $NetBSD: Makefile,v 1.17 2023/07/06 09:38:08 wiz Exp $

DISTNAME=	Archive-Tar-Wrapper-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Archive::Tar::Wrapper
COMMENT=	API wrapper around the 'tar' utility
LICENSE=	gnu-gpl-v3

DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
TEST_DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
TEST_DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run
TEST_DEPENDS+=	p5-Dumbbench-[0-9]*:../../benchmarks/p5-Dumbbench

PERL5_PACKLIST=	auto/Archive/Tar/Wrapper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
