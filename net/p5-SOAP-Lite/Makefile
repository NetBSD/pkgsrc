# $NetBSD: Makefile,v 1.57 2019/08/11 13:22:26 wiz Exp $

DISTNAME=	SOAP-Lite-1.27
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://www.soaplite.com/
#HOMEPAGE=	http://search.cpan.org/dist/SOAP-Lite/
COMMENT=	Perl5 module providing a lightweight interface to SOAP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
#DEPENDS+=	{perl>=5.10.0,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress
DEPENDS+=	p5-IO-SessionData>=1.03:../../net/p5-IO-SessionData
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-LWP-Protocol-https>=0:../../www/p5-LWP-Protocol-https
#DEPENDS+=	{perl>=5.10.0,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-tools>=0:../../mail/p5-MIME-tools
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww

BUILD_DEPENDS+=	p5-XML-Parser-Lite>=0:../../textproc/p5-XML-Parser-Lite
# for make test
BUILD_DEPENDS+=	p5-Test-Warn>=0:../../devel/p5-Test-Warn

SUPERSEDES+=	p5-SOAP-Transport-TCP-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}

REPLACE_PERL+=	bin/SOAPsh.pl bin/stubmaker.pl

PERL5_PACKLIST=	auto/SOAP/Lite/.packlist

MAKE_PARAMS+=	--noprompt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
