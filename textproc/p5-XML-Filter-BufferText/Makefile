# $NetBSD: Makefile,v 1.2 2004/12/20 11:31:10 grant Exp $

DISTNAME=	XML-Filter-BufferText-1.01
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	
PKGREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-BufferText/
COMMENT=	Perl5 module XML parser filter to put all characters() in one event

DEPENDS+=	p5-XML-SAX>=0.04:../../textproc/p5-XML-SAX

USE_BUILDLINK3=		YES
USE_LANGUAGES=		# empty
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/XML/Filter/BufferText/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
