# $NetBSD: Makefile,v 1.19 2012/10/03 21:56:32 wiz Exp $

DISTNAME=	Sendmail-AccessDB-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	mail perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sendmail/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Sendmail-AccessDB/
COMMENT=	Perl5 module for manipulating the sendmail accessdb

DEPENDS+=	p5-BerkeleyDB-[0-9]*:../../databases/p5-BerkeleyDB

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Sendmail/AccessDB/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
