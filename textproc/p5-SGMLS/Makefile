# $NetBSD: Makefile,v 1.10 2013/05/31 12:42:12 wiz Exp $
#

DISTNAME=		SGMLSpm-1.03ii
PKGNAME=		p5-SGMLS-1.03.2
PKGREVISION=		5
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../by-authors/id/D/DM/DMEGG/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/SGMLSpm-1.03ii/
COMMENT=		Class for postprocessing the output from the sgmls and nsgmls parsers

USE_LANGUAGES=		# empty

INSTALL_TARGET=		install install_html
WRKSRC=			${WRKDIR}/SGMLSpm
MAKE_ENV+=		PERL5_SUB_INSTALLVENDORLIB=${PERL5_SUB_INSTALLVENDORLIB:Q}
MAKE_ENV+=		PERL5=${PERL5:Q}
PLIST_SUBST+=		PERL5_SUB_INSTALLVENDORLIB=${PERL5_SUB_INSTALLVENDORLIB:Q}

PERL5_USE_PACKLIST=	no

INSTALLATION_DIRS+=	bin

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
