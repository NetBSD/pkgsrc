# $NetBSD: Makefile,v 1.25 2020/09/08 13:16:44 wiz Exp $

DISTNAME=	Lchown-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/N/NC/NCLEATON/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Lchown
COMMENT=	Perl5 module interface to the lchown() system call
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=		c

PERL5_PACKLIST=		auto/Lchown/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
