# $NetBSD: Makefile,v 1.2 2004/11/12 07:11:44 erh Exp $

DISTNAME=	XML-Filter-Reindent-0.03
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TJ/TJMATHER/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-Reindent-0.03/
COMMENT=	Reformats whitespace for pretty printing XML

CONFLICTS+=	p5-libxml-enno-[0-9]*

DEPENDS+=	p5-XML-Filter-DetectWS>=0.01:../../textproc/p5-XML-Filter-DetectWS

USE_BUILDLINK3=		YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Filter/Reindent/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
