# $NetBSD: Makefile,v 1.20 2011/08/06 13:33:33 adam Exp $

DISTNAME=	Convert-TNEF-0.17
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
SVR4_PKGNAME=	p5tnf
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-TNEF/
COMMENT=	Perl5 module interface to read TNEF files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
