# $NetBSD: Makefile,v 1.15 2008/06/12 02:14:50 joerg Exp $
#

DISTNAME=	Text-Wrapper-1.000
PKGNAME=	p5-Text-Wrapper-1.0
SVR4_PKGNAME=	p5twr
PKGREVISION=	2
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	Perl5 module that provides simple word wrapping

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Wrapper/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
