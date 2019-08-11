# $NetBSD: Makefile,v 1.23 2019/08/11 13:19:08 wiz Exp $

DISTNAME=	Curses-UI-0.9609
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Curses/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Curses-UI
COMMENT=	Curses based user user interface framework
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Curses>=1.29:../../devel/p5-Curses
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey
BUILD_DEPENDS+=	p5-Test-Pod>=1.20:../../devel/p5-Test-Pod

# Make Curses-UI use Curses' wide character aware functions
SUBST_CLASSES+=		wide
SUBST_STAGE.wide=	pre-configure
SUBST_MESSAGE.wide=	Upgrading to use wide-character-aware Curses functions
SUBST_FILES.wide=	lib/Curses/UI.pm
SUBST_FILES.wide+=	lib/Curses/UI/*.pm
SUBST_FILES.wide+=	lib/Curses/UI/*/*.pm
SUBST_SED.wide=		-e 's/getch/getchar/g'
SUBST_SED.wide+=	-e 's/addstr/addstring/g'

PERL5_PACKLIST=		auto/Curses/UI/.packlist

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
