# $NetBSD: Makefile,v 1.19 2016/06/08 19:24:25 wiz Exp $

DISTNAME=	Lchown-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NC/NCLEATON/
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lchown/
COMMENT=	Perl5 module interface to the lchown() system call
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES+=		c

PERL5_PACKLIST=		auto/Lchown/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
