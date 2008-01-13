# $NetBSD: Makefile,v 1.4 2008/01/13 18:23:39 heinz Exp $

DISTNAME=	Text-WrapI18N-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-WrapI18N/
COMMENT=	Perl5 module to wrap internationalized text

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Text-CharWidth-[0-9]*:../../textproc/p5-Text-CharWidth

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Text/WrapI18N/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
