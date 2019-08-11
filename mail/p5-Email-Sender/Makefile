# $NetBSD: Makefile,v 1.33 2019/08/11 13:21:33 wiz Exp $

DISTNAME=	Email-Sender-1.300031
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Email-Sender
COMMENT=	Email::Sender - a library for sending email
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Email-Abstract>=3.006:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moo>=2.000000:../../devel/p5-Moo
DEPENDS+=	p5-Net>=3.07:../../net/p5-Net
DEPENDS+=	p5-Throwable>=0.200003:../../devel/p5-Throwable
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
DEPENDS+=	p5-MooX-Types-MooseLike>=0.15:../../devel/p5-MooX-Types-MooseLike
DEPENDS+=	p5-Module-Runtime>=0:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter

# for make test
BUILD_DEPENDS+=	p5-Capture-Tiny>=0.08:../../devel/p5-Capture-Tiny

PERL5_PACKLIST=	auto/Email/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
