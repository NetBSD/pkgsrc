# $NetBSD: Makefile,v 1.5 2008/06/12 02:14:48 joerg Exp $
#

DISTNAME=		Lingua-Preferred-0.2.4
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Choose a preferred language from a selection

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Lingua/Preferred/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
