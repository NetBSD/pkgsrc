# $NetBSD: Makefile,v 1.21 2023/07/06 09:41:31 wiz Exp $

DISTNAME=	File-chmod-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/File::chmod
COMMENT=	Perl API-Implements symbolic and ls chmod modes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/chmod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
