# $NetBSD: Makefile,v 1.1.1.1 2006/01/13 18:15:09 wiz Exp $
#

DISTNAME=		SGMLSpm-1.03ii
PKGNAME=		p5-SGMLS-1.03.2
CATEGORIES=		textproc
MASTER_SITES=		http://search.cpan.org/CPAN/authors/id/D/DM/DMEGG/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://search.cpan.org/~dmegg/SGMLSpm-1.03ii/
COMMENT=		Class for postprocessing the output from the sgmls and nsgmls parsers

INSTALL_TARGET=		install install_html
WRKSRC=			${WRKDIR}/SGMLSpm
MAKE_ENV+=		PERL5_SUB_INSTALLVENDORLIB=${PERL5_SUB_INSTALLVENDORLIB:Q}
MAKE_ENV+=		PERL5=${PERL5:Q}
PLIST_SUBST+=		PERL5_SUB_INSTALLVENDORLIB=${PERL5_SUB_INSTALLVENDORLIB:Q}

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
