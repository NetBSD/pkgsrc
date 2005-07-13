# $NetBSD: Makefile,v 1.3 2005/07/13 18:01:34 jlam Exp $

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

PERL5_PACKLIST=	auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
