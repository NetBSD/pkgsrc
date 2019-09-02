# $NetBSD: Makefile,v 1.14 2019/09/02 12:29:55 adam Exp $

DISTNAME=	Danga-Socket-1.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	net perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BR/BRADFITZ/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/B/BR/BRADFITZ/
COMMENT=	Event loop and event-driven async socket base class
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Sys-Syscall>=0:../../devel/p5-Sys-Syscall
#DEPENDS+=	{perl>=5.7.3,p5-Time-HiRes>=0}:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/Danga/Socket/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
