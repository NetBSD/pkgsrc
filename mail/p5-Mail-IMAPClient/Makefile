# $NetBSD: Makefile,v 1.37 2013/12/09 14:17:49 obache Exp $

DISTNAME=	Mail-IMAPClient-3.33
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5mic
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mail-IMAPClient/
COMMENT=	Perl5 module for talking to RFC-2060 IMAP servers
LICENSE=	gnu-gpl-v2 # OR artistic

DEPENDS+=	{perl>=5.6.1,p5-File-Temp-[0-9]*}:../../devel/p5-File-Temp
DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64-[0-9]*}:../../converters/p5-MIME-Base64
DEPENDS+=	p5-Parse-RecDescent>=1.94:../../devel/p5-Parse-RecDescent
DEPENDS+=	p5-Scalar-List-Utils>=0:../../devel/p5-Scalar-List-Utils

# Recommended
DEPENDS+=	p5-Authen-SASL-[0-9]*:../../security/p5-Authen-SASL
DEPENDS+=	p5-Digest-HMAC-[0-9]*:../../security/p5-Digest-HMAC
DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod
DEPENDS+=	p5-IO-Socket-SSL-[0-9]*:../../security/p5-IO-Socket-SSL

PERL5_PACKLIST=		auto/Mail/IMAPClient/.packlist

pre-configure:
	cd ${WRKSRC} && ${TOUCH} ${TOUCH_FLAGS} test.txt

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
