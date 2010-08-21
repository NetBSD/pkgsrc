# $NetBSD: Makefile,v 1.8 2010/08/21 16:35:53 seb Exp $
#

DISTNAME=		Lingua-EN-Numbers-Ordinate-1.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		textproc perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Lingua/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Lingua-EN-Numbers-Ordinate/
COMMENT=		Go from cardinal number (3) to ordinal ("3rd")

PKG_DESTDIR_SUPPORT=	user-destdir

#DEPENDS+=		p5-Array-Compare-[0-9]*:../../devel/p5-Array-Compare

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Lingua/EN/Numbers/Ordinate/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
