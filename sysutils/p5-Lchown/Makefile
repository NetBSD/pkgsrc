# $NetBSD: Makefile,v 1.1.1.1 2004/10/11 09:41:31 kim Exp $

DISTNAME=	Lchown-0.07
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lc
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NC/NCLEATON/
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	tech-pkg@NetBSD.org
COMMENT=	Perl5 module interface to the lchown() system call

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Lchown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
