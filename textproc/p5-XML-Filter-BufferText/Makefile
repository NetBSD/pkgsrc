# $NetBSD: Makefile,v 1.7 2005/12/27 13:54:59 seb Exp $

DISTNAME=	XML-Filter-BufferText-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
#SVR4_PKGNAME=
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/XML-Filter-BufferText/
COMMENT=	Perl5 module XML parser filter to put all characters() in one event

DEPENDS+=	p5-XML-SAX>=0.04:../../textproc/p5-XML-SAX

USE_LANGUAGES=		# empty
PERL5_PACKLIST=	auto/XML/Filter/BufferText/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
