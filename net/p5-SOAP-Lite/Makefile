# $NetBSD: Makefile,v 1.26 2009/06/01 19:38:57 sno Exp $
#

DISTNAME=	SOAP-Lite-0.710.08
PKGNAME=	p5-${DISTNAME:S/710.08/71.08/}
PKGREVISION=	5
CATEGORIES=	net perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SOAP/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.soaplite.com/
#HOMEPAGE=	http://search.cpan.org/dist/SOAP-Lite/
COMMENT=	Perl5 module providing a lightweight interface to SOAP

DEPENDS+=	p5-IO-Compress>=2.017:../../devel/p5-IO-Compress
DEPENDS+=	p5-Crypt-SSLeay>=0:../../security/p5-Crypt-SSLeay
DEPENDS+=	p5-FCGI>=0:../../www/p5-FCGI
DEPENDS+=	p5-libwww>=0:../../www/p5-libwww
DEPENDS+=	p5-IO-Socket-SSL>=0:../../security/p5-IO-Socket-SSL
DEPENDS+=	p5-MIME-Base64-[0-9]*:../../converters/p5-MIME-Base64
DEPENDS+=	p5-MIME-Lite>=0:../../mail/p5-MIME-Lite
DEPENDS+=	p5-MIME-tools>=0:../../mail/p5-MIME-tools
DEPENDS+=	{perl>=5.10,p5-Net>=0}:../../net/p5-Net
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	{perl>=5.10.0,p5-version>=0}:../../devel/p5-version
DEPENDS+=	p5-XML-Parser>=2.23:../../textproc/p5-XML-Parser

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/${DISTNAME:C|[a-z]$||}

REPLACE_PERL+=	bin/SOAPsh.pl bin/XMLRPCsh.pl bin/stubmaker.pl

PERL5_PACKLIST=	auto/SOAP/Lite/.packlist

MAKE_PARAMS+=	--noprompt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
