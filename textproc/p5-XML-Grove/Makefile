# $NetBSD: Makefile,v 1.7 2002/10/27 19:30:25 seb Exp $
#

DISTNAME=	XML-Grove-0.46alpha
PKGNAME=	p5-${DISTNAME:S/alpha/.0.1/}
SVR4_PKGNAME=	p5xgr
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	explorer@netbsd.org
#HOMEPAGE=	
COMMENT=	Perl 5 module providing simple objects for parsed XML documents

DEPENDS+=	p5-libxml>=0.0.7:../../textproc/p5-libxml

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/XML/Grove/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
