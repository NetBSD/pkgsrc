# $NetBSD: Makefile,v 1.6 2002/07/01 11:36:45 wiz Exp $
#

DISTNAME=	XML-Grove-0.46alpha
PKGNAME=	p5-${DISTNAME:S/alpha/.0.1/}
SVR4_PKGNAME=	p5xgr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

DEPENDS+=	p5-libxml>=0.0.7:../../textproc/p5-libxml

MAINTAINER=	explorer@netbsd.org
#HOMEPAGE=	
COMMENT=	Perl 5 module providing simple objects for parsed XML documents

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Grove/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
