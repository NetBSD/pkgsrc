# $NetBSD: Makefile,v 1.7 2012/10/03 21:56:26 wiz Exp $
#

DISTNAME=	Email-Date-Format-1.002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Email/}

MAINTAINER=	rhaen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Email-Date-Format/
COMMENT=	Perl Module to produce RFC 2822 date strings
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	{perl>=5,p5-Time-Local-[0-9]*}:../../time/p5-Time-Local

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Email/Date/Format/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
