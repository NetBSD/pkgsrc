# $NetBSD: Makefile,v 1.3 2001/07/20 07:51:52 wiz Exp $
#

DISTNAME=	XML-Grove-0.46alpha
PKGNAME=	p5-${DISTNAME:S/alpha/.0.1/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	explorer@netbsd.org
#HOMEPAGE=	
COMMENT=	Perl 5 module providing simple objects for parsed XML documents

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Grove/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
