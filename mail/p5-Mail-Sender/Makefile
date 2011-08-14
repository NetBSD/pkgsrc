# $NetBSD: Makefile,v 1.5 2011/08/14 13:25:27 obache Exp $
#

DISTNAME=	Mail-Sender-0.8.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Mail/}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~jenda/Mail-Sender/
COMMENT=	Sending mails with attachments through an SMTP server

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MIME-Base64>=0:../../converters/p5-MIME-Base64

PERL5_PACKLIST=	auto/Mail/Sender/.packlist

BUILD_TARGET=pure_all
INSTALL_TARGET=pure_install

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
