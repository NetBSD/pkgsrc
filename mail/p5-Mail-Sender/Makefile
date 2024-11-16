# $NetBSD: Makefile,v 1.28 2024/11/16 12:05:53 wiz Exp $

DISTNAME=	Mail-Sender-0.903
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CAPOEIRAB/Mail-Sender-0.903
COMMENT=	Sending mails with attachments through an SMTP server
LICENSE=	${PERL5_LICENSE}

#DEPENDS+=	{perl>=5.7.3,p5-MIME-Base64>=0}:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/Mail/Sender/.packlist

BUILD_TARGET=	pure_all
INSTALL_TARGET=	pure_install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
