# $NetBSD: Makefile,v 1.13 2006/10/04 22:01:00 wiz Exp $

DISTNAME=	Text-BibTeX-0.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tbt
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/btOOL/}
DISTFILES+=	${DISTNAME}.tar.gz btparse-0.32.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerg.ca/software/btOOL/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files

PERL5_PACKLIST=		auto/Text/BibTeX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
