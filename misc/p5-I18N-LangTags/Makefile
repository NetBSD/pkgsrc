# $NetBSD: Makefile,v 1.10 2010/08/21 16:35:17 seb Exp $
#

DISTNAME=		I18N-LangTags-0.35
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		3
SVR4_PKGNAME=		p5ilt
CATEGORIES=		misc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=I18N/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/I18N-LangTags/
COMMENT=		Perl5 functions for dealing with RFC3066-style language tags

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/I18N/LangTags/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
