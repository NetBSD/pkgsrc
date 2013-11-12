# $NetBSD: Makefile,v 1.39 2013/11/12 13:31:38 wen Exp $

DISTNAME=	SOAP-Lite-1.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.soaplite.com/
#HOMEPAGE=	http://search.cpan.org/dist/SOAP-Lite/
COMMENT=	Perl5 module providing a lightweight interface to SOAP
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Inspector-[0-9]*:../../devel/p5-Class-Inspector
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-FCGI>=0:../../www/p5-FCGI
DEPENDS+=	{perl>=5.10.0,p5-IO-Compress>=2.017}:../../devel/p5-IO-Compress
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	{perl>=5.10.0,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-Lite>=0:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools>=0:../../mail/p5-MIME-tools
DEPENDS+=	{perl>=5.10,p5-Net>=0}:../../net/p5-Net
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser
DEPENDS+=	{perl>=5.10.1,p5-constant>=1.14}:../../devel/p5-constant
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	{perl>=5.10.0,p5-version>=0}:../../devel/p5-version

SUPERSEDES+=	p5-SOAP-Transport-TCP-[0-9]*

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}

REPLACE_PERL+=	bin/SOAPsh.pl bin/XMLRPCsh.pl bin/stubmaker.pl

PERL5_PACKLIST=	auto/SOAP/Lite/.packlist

MAKE_PARAMS+=	--noprompt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
