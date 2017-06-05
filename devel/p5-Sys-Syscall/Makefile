# $NetBSD: Makefile,v 1.9 2017/06/05 14:23:37 ryoon Exp $
#

DISTNAME=	Sys-Syscall-0.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sys/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sys-Syscall/lib/Sys/Syscall.pm

COMMENT=	Access system calls that Perl doesn't normally provide access to
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sys/Syscall/.packlist
USE_LANGUAGES=	# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
