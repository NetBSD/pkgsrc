# $NetBSD: Makefile,v 1.16 2011/08/14 13:45:16 obache Exp $
#

DISTNAME=		Locale-Maketext-1.13
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5lmt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

PKG_FAIL_REASON=	"In Perl5 Core since 5.10.1"

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext/
COMMENT=		Perl framework for localization

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		{perl>=5.10.0,p5-I18N-LangTags>=0.30}:../../misc/p5-I18N-LangTags

PERL5_PACKLIST=		auto/Locale-Maketext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
