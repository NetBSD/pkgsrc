# $NetBSD: Makefile,v 1.9 2013/05/31 12:41:56 wiz Exp $

DISTNAME=	Digest-MD5-File-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5m5f
CATEGORIES=	security perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Digest/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Digest-MD5-File/
COMMENT=	Perl5 extension for getting MD5 sums for files and urls
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=	{perl>=5.7.3,p5-Digest-MD5-[0-9]*}:../../security/p5-Digest-MD5
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww

PERL5_PACKLIST=		auto/Digest/MD5/File/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
