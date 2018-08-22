# $NetBSD: Makefile,v 1.31 2018/08/22 09:44:09 wiz Exp $

DISTNAME=	IO-Stty-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=IO/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl class for I/O on tty devices
HOMEPAGE=	http://search.cpan.org/dist/IO-Stty/
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	#empty

PERL5_PACKLIST=		auto/IO/Stty/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
