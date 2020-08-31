# $NetBSD: Makefile,v 1.18 2020/08/31 18:08:05 wiz Exp $
#

DISTNAME=	FileHandle-Fmode-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FileHandle-Fmode
COMMENT=	Perl 5 module to determine how a filehandle is opened
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/FileHandle/Fmode/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
