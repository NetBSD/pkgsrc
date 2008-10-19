# $NetBSD: Makefile,v 1.7 2008/10/19 19:17:54 he Exp $
#

DISTNAME=		File-HomeDir-0.80
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=File/}

MAINTAINER=		bartosz@atom.eu.org
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
