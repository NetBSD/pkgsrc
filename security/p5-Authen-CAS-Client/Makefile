# $NetBSD: Makefile,v 1.3 2009/05/10 20:01:09 seb Exp $
#

DISTNAME=	Authen-CAS-Client-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Authen/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Authen-CAS-Client/
COMMENT=	Perl 5 module providing an interface for JA-SIG's CAS

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Authen/CAS/Client/.packlist

BUILD_DEPENDS+=	p5-Test-MockObject-[0-9]*:../../devel/p5-Test-MockObject
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-XML-LibXML-[0-9]*:../../textproc/p5-XML-LibXML
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
