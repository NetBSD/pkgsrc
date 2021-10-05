# $NetBSD: Makefile,v 1.1 2021/10/05 12:57:48 gdt Exp $

DISTNAME=	Sys-Mmap-0.20
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/T/TO/TODDR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Sys::Mmap
COMMENT=	Uses mmap to map in a file as a Perl variable
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Sys/Mmap/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
