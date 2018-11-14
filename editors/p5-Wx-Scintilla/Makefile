# $NetBSD: Makefile,v 1.31 2018/11/14 22:21:24 kleink Exp $

DISTNAME=	Wx-Scintilla-0.39
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	27
CATEGORIES=	editors x11 perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Wx/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Wx-Scintilla/
COMMENT=	Scintilla source code editing component for wxWidgets
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Alien-wxWidgets-[0-9]*:../../x11/p5-Alien-wxWidgets
#BUILD_DEPENDS+=	{perl>=5.16.6,p5-ExtUtils-ParseXS>=3.15}:../../devel/p5-ExtUtils-ParseXS

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/blib/arch/auto/Wx/Scintilla

USE_TOOLS+=	perl
USE_LANGUAGES+=		c c++

PERL5_PACKLIST=		auto/Wx/Scintilla/.packlist
PERL5_MODULE_TYPE=	Module::Build

BUILDLINK_DEPMETHOD.p5-Wx=	build
.include "../../x11/p5-Wx/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
