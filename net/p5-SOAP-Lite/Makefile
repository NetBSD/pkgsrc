# $NetBSD: Makefile,v 1.13 2006/10/21 17:11:47 obache Exp $
#

DISTNAME=	SOAP-Lite-0.69
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://soaplite.com/
COMMENT=	Perl5 module providing a lightweight interface to SOAP

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

PERL5_PACKLIST=	auto/SOAP/Lite/.packlist

MAKE_PARAMS+=	</dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
