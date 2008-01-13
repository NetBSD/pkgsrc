# $NetBSD: Makefile,v 1.4 2008/01/13 18:22:08 heinz Exp $

DISTNAME=	Text-CharWidth-0.04
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-CharWidth/
COMMENT=	Perl5 wrappers around wcwidth(3) and family

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Text/CharWidth/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
