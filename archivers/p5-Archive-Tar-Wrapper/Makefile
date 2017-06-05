# $NetBSD: Makefile,v 1.6 2017/06/05 14:22:16 ryoon Exp $

DISTNAME=	Archive-Tar-Wrapper-0.23
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Archive/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mschilli/Archive-Tar-Wrapper/
COMMENT=	API wrapper around the 'tar' utility
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Log-Log4perl-[0-9]*:../../devel/p5-Log-Log4perl
BUILD_DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
BUILD_DEPENDS+=	p5-IPC-Run-[0-9]*:../../devel/p5-IPC-Run

PERL5_PACKLIST=	auto/Archive/Tar/Wrapper/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
