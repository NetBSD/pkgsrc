# $NetBSD: Makefile,v 1.8 2009/03/01 21:15:50 sno Exp $
#

DISTNAME=		File-HomeDir-0.82
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		pkgsrc-users@netbsd.org
HOMEPAGE=		http://search.cpan.org/dist/File-HomeDir/
COMMENT=		Get the home directory for yourself or other users

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/File/HomeDir/.packlist

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
DEPENDS+=		p5-Mac-Carbon>=0.77:../../devel/p5-Mac-Carbon
.endif

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
