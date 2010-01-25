# $NetBSD: Makefile,v 1.12 2010/01/25 12:55:47 sno Exp $
#

DISTNAME=		File-HomeDir-0.89
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/File-HomeDir/
COMMENT=		Get the home directory for yourself or other users
LICENSE=		${PERL5_LICENSE}

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/HomeDir/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=		p5-Mac-Carbon>=0.77:../../devel/p5-Mac-Carbon
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
