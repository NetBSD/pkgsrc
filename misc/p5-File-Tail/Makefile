# $NetBSD: Makefile,v 1.5 2006/03/04 21:30:12 jlam Exp $

DISTNAME=	File-Tail-0.99.1
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5fit
PKGREVISION=	1
CATEGORIES=	misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://theory.uwinnipeg.ca/CPAN/data/File-Tail/File/Tail.html
COMMENT=	Perl5 module for reading from continuously updated files

DEPENDS+=	p5-Time-HiRes-[0-9]*:../../time/p5-Time-HiRes

PERL5_PACKLIST=	auto/File/Tail/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
