# $NetBSD: Makefile,v 1.1.1.1 2011/04/05 00:47:14 manu Exp $

DISTNAME=	XML-Entities-1.0000
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5ent
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=XML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~sixtease/XML-Entities-1.0000/lib/XML/Entities.pm
COMMENT=	Decode strings with XML entities
LICENSE=	${PERL5_LICENSE}

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=		${WRKDIR}/XML-Entities

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/XML/Entities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
