# $NetBSD: Makefile,v 1.7 2004/05/04 23:46:36 snj Exp $

DISTNAME=	Text-BibTeX-0.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tbt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/btOOL/}
DISTFILES+=	${DISTNAME}.tar.gz btparse-0.32.tar.gz

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/BibTeX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
