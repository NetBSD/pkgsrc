# $NetBSD: Makefile,v 1.9 2011/08/14 13:25:24 obache Exp $

DISTNAME=	Email-Sender-0.102370
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Sender/
COMMENT=	Email::Sender - a library for sending email
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Capture-Tiny>=0.08:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-Email-Abstract>=3:../../mail/p5-Email-Abstract
DEPENDS+=	p5-Email-Address-[0-9]*:../../mail/p5-Email-Address
DEPENDS+=	p5-Email-Simple>=1.998:../../mail/p5-Email-Simple
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose>=0.70:../../devel/p5-Moose
DEPENDS+=	{perl>=5.10,p5-Net-[0-9]*}:../../net/p5-Net
DEPENDS+=	p5-Throwable>=0.100090:../../devel/p5-Throwable
DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny

PERL5_PACKLIST=	auto/Email/Sender/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
