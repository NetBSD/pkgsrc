# $NetBSD: Makefile,v 1.8 2013/03/16 22:47:15 dholland Exp $
#

DISTNAME=	LaTeX-Driver-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=LaTeX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/LaTeX-Driver/
COMMENT=	Perl module encapsulates the details of invoking the Latex programs
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	makeindexk-[0-9]*:../../textproc/makeindexk
DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Exception-Class-[0-9]*:../../devel/p5-Exception-Class
DEPENDS+=	p5-File-Slurp-[0-9]*:../../devel/p5-File-Slurp
DEPENDS+=	tex-latex-bin-[0-9]*:../../print/tex-latex-bin
DEPENDS+=	web2c-[0-9]*:../../print/web2c
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk

.include "../../print/ghostscript/ghostscript.mk"

PERL5_PACKLIST=		auto/LaTeX/Driver/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
