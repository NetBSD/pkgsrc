# $NetBSD: Makefile,v 1.17 2008/07/27 20:56:27 he Exp $
#

DISTNAME=	SOAP-Lite-0.710.08
PKGNAME=	p5-${DISTNAME:S/710.08/71.08/}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.soaplite.com/
#HOMEPAGE=	http://search.cpan.org/dist/SOAP-Lite/
COMMENT=	Perl5 module providing a lightweight interface to SOAP

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

REPLACE_PERL+=	bin/SOAPsh.pl bin/XMLRPCsh.pl bin/stubmaker.pl

PERL5_PACKLIST=	auto/SOAP/Lite/.packlist

MAKE_PARAMS+=	</dev/null

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
