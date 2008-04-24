# $NetBSD: Makefile,v 1.14 2008/04/24 21:20:46 markd Exp $

DISTNAME=	Text-BibTeX-0.37
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tbt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}
DISTFILES+=	${DISTNAME}.tar.gz btparse-0.35.tar.gz
SITES.btparse-0.35.tar.gz=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/A/AM/AMBS/btparse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gerg.ca/software/btOOL/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/BibTeX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
