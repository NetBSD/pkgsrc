# $NetBSD: Makefile,v 1.5 2004/05/16 23:17:33 grant Exp $
#

DISTNAME=	SOAP-Lite-0.60a
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://soaplite.com/
COMMENT=	Perl5 module providing a lightweight interface to SOAP

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/SOAP/Lite/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
