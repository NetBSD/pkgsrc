# $NetBSD: Makefile,v 1.5 2011/08/14 15:14:12 obache Exp $

DISTNAME=       Text-Emoticon-0.04
PKGNAME=        p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MI/MIYAGAWA/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Emoticon/
COMMENT=	Emoticon filter class

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-UNIVERSAL-require-[0-9]*:../../devel/p5-UNIVERSAL-require

PERL5_PACKLIST=		auto/Text/Emoticon/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
