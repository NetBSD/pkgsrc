# $NetBSD: Makefile,v 1.14 2012/10/25 06:56:28 asau Exp $
#

DISTNAME=		Text-Shellwords-1.08
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=		dprice@cs.nmsu.edu
HOMEPAGE=		http://search.cpan.org/dist/Text-Shellwords/
COMMENT=		Wrapper around shellwords.pl package

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/Text/Shellwords/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
