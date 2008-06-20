# $NetBSD: Makefile,v 1.17 2008/06/20 01:09:09 joerg Exp $

DISTNAME=		Convert-TNEF-0.17
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tnf
PKGREVISION=		2
CATEGORIES=		converters perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl5 module interface to read TNEF files

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-MIME-tools-[0-9]*:../../mail/p5-MIME-tools

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Convert/TNEF/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
