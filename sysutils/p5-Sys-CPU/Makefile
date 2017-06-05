# $NetBSD: Makefile,v 1.4 2017/06/05 14:24:37 ryoon Exp $

DISTNAME=	Sys-CPU-0.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MZ/MZSANFORD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mzsanford/Sys-CPU/
COMMENT=	Perl 5 module for getting CPU information
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c
PERL5_PACKLIST= auto/Sys/CPU/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
