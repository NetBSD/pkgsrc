# $NetBSD: Makefile,v 1.5 2003/06/02 01:16:33 jschauma Exp $

DISTNAME=	Text-BibTeX-0.33
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5tbt
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=biblio/bibtex/utils/btOOL/}
DISTFILES+=	${DISTNAME}.tar.gz btparse-0.32.tar.gz

MAINTAINER=	tech-pkg@netbsd.org
HOMEPAGE=	http://starship.python.net/~gward/btOOL/
COMMENT=	Perl library for reading, parsing, and processing BibTeX files

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Text/BibTeX/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
