# $NetBSD: Makefile,v 1.6 2005/08/06 06:19:31 jlam Exp $

DISTNAME=	Lchown-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lc
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NC/NCLEATON/
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lchown/
COMMENT=	Perl5 module interface to the lchown() system call

PERL5_PACKLIST=		auto/Lchown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
