# $NetBSD: Makefile,v 1.2 2010/08/04 22:08:39 seb Exp $

DISTNAME=	Vroom-0.23
PKGNAME=	p5-${DISTNAME}
#PKGREVISION=	1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/I/IN/INGY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Vroom/
COMMENT=	Slide Shows in Vim
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_PACKLIST= auto/Vroom/.packlist

DEPENDS+=	p5-Class-Field-[0-9]*:../../devel/p5-Class-Field
DEPENDS+=	p5-File-HomeDir-[0-9]*:../../devel/p5-File-HomeDir
DEPENDS+=	p5-IO-All-[0-9]*:../../devel/p5-IO-All
DEPENDS+=	p5-Template-Toolkit-Simple-[0-9]*:../../www/p5-Template-Toolkit-Simple
DEPENDS+=	p5-YAML-LibYAML-[0-9]*:../../textproc/p5-YAML-LibYAML

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
