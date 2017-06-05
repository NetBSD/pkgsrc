# $NetBSD: Makefile,v 1.15 2017/06/05 14:24:45 ryoon Exp $
#

DISTNAME=		SGMLSpm-1.03ii
PKGNAME=		p5-SGMLS-1.03.2
PKGREVISION=		9
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=SGMLS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/SGMLSpm/
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
