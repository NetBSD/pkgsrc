# $NetBSD: Makefile,v 1.22 2016/01/30 14:57:56 mef Exp $

DISTNAME=	Email-Sender-1.300021
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Sender/
COMMENT=	Email::Sender - a library for sending email
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Capture-Tiny>=0.08:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Email-Abstract>=3:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moo>=1.000008:../../devel/p5-Moo
#DEPENDS+=	{perl>=5.10,p5-Net-[0-9]*}:../../net/p5-Net
DEPENDS+=	p5-Throwable>=0.200003:../../devel/p5-Throwable
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

# for make test
BUILD_DEPENDS+=	p5-MooX-Types-MooseLike-[0-9]*:../../devel/p5-MooX-Types-MooseLike

PERL5_PACKLIST=	auto/Email/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
