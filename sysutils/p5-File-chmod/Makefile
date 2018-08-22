# $NetBSD: Makefile,v 1.14 2018/08/22 09:46:37 wiz Exp $

DISTNAME=	File-chmod-0.42
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	perl5 sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/CPAN/authors/id/P/PI/PINYAN/
COMMENT=	Perl API-Implements symbolic and ls chmod modes
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/File/chmod/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
