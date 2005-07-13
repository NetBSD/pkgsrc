# $NetBSD: Makefile,v 1.5 2005/07/13 18:01:40 jlam Exp $

DISTNAME=	Lchown-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lc
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NC/NCLEATON/
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lchown/
COMMENT=	Perl5 module interface to the lchown() system call

PERL5_PACKLIST=		auto/Lchown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
