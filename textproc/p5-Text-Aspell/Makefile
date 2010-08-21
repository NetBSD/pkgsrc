# $NetBSD: Makefile,v 1.2 2010/08/21 16:36:02 seb Exp $
#

DISTNAME=	Text-Aspell-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=	p5tas
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Text-Aspell/
COMMENT=	Perl interface to the GNU Aspell library

BUILD_DEPENDS+=	aspell-english>0:../../textproc/aspell-english

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Text/Aspell/.packlist

.include "../../textproc/aspell/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
