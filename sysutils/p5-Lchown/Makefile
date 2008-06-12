# $NetBSD: Makefile,v 1.8 2008/06/12 02:14:46 joerg Exp $

DISTNAME=	Lchown-1.00
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5lc
PKGREVISION=	1
CATEGORIES=	sysutils perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/N/NC/NCLEATON/
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Lchown/
COMMENT=	Perl5 module interface to the lchown() system call

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Lchown/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
