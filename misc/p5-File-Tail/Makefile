# $NetBSD: Makefile,v 1.1.1.1 2004/12/31 21:35:05 kim Exp $

DISTNAME=	File-Tail-0.99.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fit
PKGREVISION=	# empty
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-Tail/File/Tail.html
COMMENT=	Perl5 module for reading from continuously updated files

DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
