# $NetBSD: Makefile,v 1.28 2019/06/30 20:15:05 nia Exp $

DISTNAME=	FileHandle-Unget-0.1634
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=FileHandle/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/FileHandle-Unget
COMMENT=	Perl5 module providing an improved filehandle
LICENSE=	gnu-gpl-v2

DEPENDS+=	p5-File-Slurper-[0-9]*:../../devel/p5-File-Slurper
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI

MAKE_ENV+=		PERL_USE_UNSAFE_INC=1
PERL5_PACKLIST=		auto/FileHandle/Unget/.packlist

# for tests:
USE_TOOLS+=	perl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
