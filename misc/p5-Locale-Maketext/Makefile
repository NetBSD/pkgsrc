# $NetBSD: Makefile,v 1.11 2008/07/23 15:36:01 rhaen Exp $
#

DISTNAME=		Locale-Maketext-1.13
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5lmt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Locale/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Locale-Maketext/
COMMENT=		Perl framework for localization

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-I18N-LangTags>=0.30:../../misc/p5-I18N-LangTags

PERL5_PACKLIST=		auto/Locale-Maketext/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
