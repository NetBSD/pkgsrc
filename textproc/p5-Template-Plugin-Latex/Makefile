# $NetBSD: Makefile,v 1.4 2011/08/14 15:14:10 obache Exp $
#

DISTNAME=	Template-Plugin-Latex-3.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Template/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Template-Plugin-Latex/
COMMENT=	Latex support for the Template Toolkit
LICENSE=	gnu-gpl-v2 # OR artistic

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Template-Toolkit>=2.16:../../www/p5-Template-Toolkit
DEPENDS+=	p5-LaTeX-Driver>=0.07:../../print/p5-LaTeX-Driver
DEPENDS+=	p5-LaTeX-Encode>=0.02:../../print/p5-LaTeX-Encode
DEPENDS+=	p5-LaTeX-Table-[0-9]*:../../print/p5-LaTeX-Table

PERL5_PACKLIST=		auto/Template/Plugin/Latex/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
