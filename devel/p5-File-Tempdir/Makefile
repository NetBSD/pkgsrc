# $NetBSD: Makefile,v 1.19 2023/07/06 09:39:13 wiz Exp $
#

DISTNAME=	File-Tempdir-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/File-Tempdir
COMMENT=	Object interface for tempdir() from Perl module File::Temp

PERL5_PACKLIST=		auto/File/Tempdir/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
